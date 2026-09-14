// 1
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

void print_file_mmap(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    if (size == -1)
    {
        perror("lseek");
        close(fd);
        return;
    }

    lseek(fd, 0, SEEK_SET);

    char *data = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return;
    }

    write(STDOUT_FILENO, data, size);

    munmap(data, size);
    close(fd);
}

int main()
{
    print_file_mmap("large.txt");
    return 0;
}
//2
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

void replace_char_in_mmap(const char *filepath, char old_c, char new_c)
{
    int fd = open(filepath, O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    if (size == -1)
    {
        perror("lseek");
        close(fd);
        return;
    }

    lseek(fd, 0, SEEK_SET);

    char *data = mmap(NULL, size, PROT_READ | PROT_WRITE,
                      MAP_SHARED, fd, 0);

    if (data == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return;
    }

    for (off_t i = 0; i < size; i++)
    {
        if (data[i] == old_c)
            data[i] = new_c;
    }

    if (msync(data, size, MS_SYNC) == -1)
        perror("msync");

    munmap(data, size);
    close(fd);
}

int main()
{
    replace_char_in_mmap("text.txt", ' ', '-');

    printf(" replaced successfully.\n");

    return 0;
}
//3
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int *create_shared_int_array(int size)
{
    int *arr = mmap(NULL,
                    size * sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                    -1,
                    0);

    if (arr == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    return arr;
}

int main()
{
    int size = 10;
    int *arr = create_shared_int_array(size);

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        munmap(arr, size * sizeof(int));
        return 1;
    }

    if (pid == 0)
    {
  
        for (int i = 0; i < size; i++)
        {
            arr[i] = i + 1;
        }

        munmap(arr, size * sizeof(int));
        exit(0);
    }
    else
    {
        // Parent process
        wait(NULL);

        int sum = 0;

        printf("Array:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
            sum += arr[i];
        }

        printf("\nSum = %d\n", sum);

        munmap(arr, size * sizeof(int));
    }

    return 0;
}
//4
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define SIZE 10

int main()
{
  
    int *malloc_arr = (int *)malloc(SIZE * sizeof(int));
    if (malloc_arr == NULL)
    {
        perror("malloc");
        return 1;
    }

  
    int *shared_arr = mmap(NULL,
                           SIZE * sizeof(int),
                           PROT_READ | PROT_WRITE,
                           MAP_SHARED | MAP_ANONYMOUS,
                           -1,
                           0);

    if (shared_arr == MAP_FAILED)
    {
        perror("mmap");
        free(malloc_arr);
        return 1;
    }

  
    for (int i = 0; i < SIZE; i++)
    {
        malloc_arr[i] = 0;
        shared_arr[i] = 0;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        free(malloc_arr);
        munmap(shared_arr, SIZE * sizeof(int));
        return 1;
    }

    if (pid == 0)
    {

        for (int i = 0; i < SIZE; i++)
        {
            malloc_arr[i] = 5;
            shared_arr[i] = 5;
        }

        printf("Child finished writing.\n");

        free(malloc_arr);
        munmap(shared_arr, SIZE * sizeof(int));
        exit(0);
    }
    else
    {
        wait(NULL);

        printf("\nParent sees malloc array:\n");
        for (int i = 0; i < SIZE; i++)
            printf("%d ", malloc_arr[i]);

        printf("\n\nParent sees shared mmap array:\n");
        for (int i = 0; i < SIZE; i++)
            printf("%d ", shared_arr[i]);

        printf("\n");

        free(malloc_arr);
        munmap(shared_arr, SIZE * sizeof(int));
    }

    return 0;
}
//5
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

struct State
{
    int turn;
    int value;
};

struct State *create_shared_state()
{
    struct State *state = mmap(NULL,
                               sizeof(struct State),
                               PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS,
                               -1,
                               0);

    if (state == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    state->turn = 0;
    state->value = 1;

    return state;
}

int main()
{
    struct State *state = create_shared_state();

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        munmap(state, sizeof(struct State));
        return 1;
    }

    if (pid == 0)
    {
        // Child
        for (int i = 0; i < 5; i++)
        {
            while (state->turn != 0)
                ;

            state->value *= 2;
            printf("Child : value = %d\n", state->value);

            state->turn = 1;
        }

        munmap(state, sizeof(struct State));
        exit(0);
    }
    else
    {
        // Parent
        for (int i = 0; i < 5; i++)
        {
            while (state->turn != 1)
                ;

            state->value *= 3;
            printf("Parent: value = %d\n", state->value);

            state->turn = 0;
        }

        wait(NULL);

        munmap(state, sizeof(struct State));
    }

    return 0;
}
//6
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

void reverse_file_in_memory(const char *filepath)
{
    int fd = open(filepath, O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return;
    }

    off_t size = lseek(fd, 0, SEEK_END);

    if (size == -1)
    {
        perror("lseek");
        close(fd);
        return;
    }

    if (size == 0)
    {
        close(fd);
        return;
    }

    char *data = mmap(NULL,
                      size,
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED,
                      fd,
                      0);

    if (data == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return;
    }

    char *left = data;
    char *right = data + size - 1;

    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    msync(data, size, MS_SYNC);

    munmap(data, size);
    close(fd);
}

int main()
{
    reverse_file_in_memory("text.txt");

    printf("File reversed .\n");

    return 0;
}
//7
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE 10000

int main()
{
    int fd = open("data.bin", O_CREAT | O_RDWR, 0666);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Ստեղծում ենք 10000 integer չափով ֆայլ
    ftruncate(fd, SIZE * sizeof(int));

    int *data = mmap(NULL,
                     SIZE * sizeof(int),
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED,
                     fd,
                     0);

    if (data == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        data[i] = rand() % 100000;
    }

    
    int *results = mmap(NULL,
                        2 * sizeof(int),
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS,
                        -1,
                        0);

    if (results == MAP_FAILED)
    {
        perror("mmap results");
        return 1;
    }

    pid_t child1 = fork();

    if (child1 == 0)
    {
        int max = data[0];

        for (int i = 1; i < 5000; i++)
        {
            if (data[i] > max)
                max = data[i];
        }

        results[0] = max;

        munmap(data, SIZE * sizeof(int));
        munmap(results, 2 * sizeof(int));

        exit(0);
    }

    pid_t child2 = fork();

    if (child2 == 0)
    {
        int max = data[5000];

        for (int i = 5001; i < SIZE; i++)
        {
            if (data[i] > max)
                max = data[i];
        }

        results[1] = max;

        munmap(data, SIZE * sizeof(int));
        munmap(results, 2 * sizeof(int));

        exit(0);
    }

    // Parent
    wait(NULL);
    wait(NULL);

    int absolute_max;

    if (results[0] > results[1])
        absolute_max = results[0];
    else
        absolute_max = results[1];

    printf("Child 1 max: %d\n", results[0]);
    printf("Child 2 max: %d\n", results[1]);
    printf("Absolute max: %d\n", absolute_max);

    munmap(data, SIZE * sizeof(int));
    munmap(results, 2 * sizeof(int));

    close(fd);

    return 0;
}
//8
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
    const char *filename = "mapped_file.txt";

    int fd = open(filename,
                  O_CREAT | O_RDWR,
                  0666);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

   
    if (ftruncate(fd, 1024) == -1)
    {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    char *ptr = mmap(NULL,
                     1024,
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED,
                     fd,
                     0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    const char *message =
        "memory mapped!";

    strcpy(ptr, message);

  
    msync(ptr, 1024, MS_SYNC);

    munmap(ptr, 1024);

    close(fd);

    printf(" successfull.\n");

    return 0;
}
//9
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
    const char *filename = "test.txt";

    int fd = open(filename, O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);

    if (size == 0)
    {
        printf("empty\n");
        close(fd);
        return 1;
    }

    char *shared_ptr = mmap(NULL,
                            size,
                            PROT_READ | PROT_WRITE,
                            MAP_SHARED,
                            fd,
                            0);

    if (shared_ptr == MAP_FAILED)
    {
        perror("shared mmap");
        close(fd);
        return 1;
    }

    char *private_ptr = mmap(NULL,
                             size,
                             PROT_READ | PROT_WRITE,
                             MAP_PRIVATE,
                             fd,
                             0);

    if (private_ptr == MAP_FAILED)
    {
        perror("private mmap");
        munmap(shared_ptr, size);
        close(fd);
        return 1;
    }

   
    shared_ptr[0] = 'S';

    
    private_ptr[0] = 'P';

    printf("Changes made.\n");
    printf("Sleeping for 10 seconds...\n");

    sleep(10);

    munmap(shared_ptr, size);
    munmap(private_ptr, size);

    close(fd);

    return 0;
}//10
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define MAX_USERS 100

struct User
{
    int id;
    char name[20];
    int age;
};

struct User *load_database(const char *filename, int max_users)
{
    int fd = open(filename,
                  O_CREAT | O_RDWR,
                  0666);

    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    if (ftruncate(fd, max_users * sizeof(struct User)) == -1)
    {
        perror("ftruncate");
        close(fd);
        exit(1);
    }

    struct User *users = mmap(NULL,
                              max_users * sizeof(struct User),
                              PROT_READ | PROT_WRITE,
                              MAP_SHARED,
                              fd,
                              0);

    if (users == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        exit(1);
    }

    close(fd);

    return users;
}

int main()
{
    struct User *users = load_database("users.db", MAX_USERS);

    int count = 0;


    for (int i = 0; i < MAX_USERS; i++)
    {
        if (users[i].id != 0)
            count++;
    }

    while (1)
    {
        int choice;

        printf("\nMENU\n");
        printf("1. Add user\n");
        printf("2. Show users\n");
        printf("3. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);

        if (choice == 1)
        {
            if (count >= MAX_USERS)
            {
                printf("full\n");
                continue;
            }

            printf("Enter id: ");
            scanf("%d", &users[count].id);

            printf("Enter name: ");
            scanf("%19s", users[count].name);

            printf("Enter age: ");
            scanf("%d", &users[count].age);

            count++;

            printf("User added.\n");
        }

        else if (choice == 2)
        {
            printf("\nUsers:\n");

            for (int i = 0; i < MAX_USERS; i++)
            {
                if (users[i].id != 0)
                {
                    printf("----------------\n");
                    printf("ID: %d\n", users[i].id);
                    printf("Name: %s\n", users[i].name);
                    printf("Age: %d\n", users[i].age);
                }
            }
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            printf("Wrong \n");
        }
    }

    msync(users,
          MAX_USERS * sizeof(struct User),
          MS_SYNC);

    munmap(users,
           MAX_USERS * sizeof(struct User));

    return 0;
}