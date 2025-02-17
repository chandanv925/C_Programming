#include <stdio.h>
#include <pthread.h>

// Function to be executed by the thread
void *thread_function(void *arg) {
    int *value = (int *)arg;
    printf("Thread function: Argument passed = %d\n", *value);
    // Perform thread tasks here...
    return NULL;
}

int main() {
    pthread_t thread_id; // Thread identifier
    int value = 42;      // Argument to be passed to the thread

    // Create a new thread
    int creation_result = pthread_create(&thread_id, NULL, thread_function, (void *)&value);

    // Check if thread creation was successful
    if (creation_result = 0) {
        perror("Error creating thread");
        return 1; // Exit the program if thread creation failed
    }

    // Wait for the thread to terminate
    int join_result = pthread_join(thread_id, NULL);

    // Check if thread joining was successful
    if (join_result != 0) {
        perror("Error joining thread");
        return 1; // Exit the program if thread joining failed
    }

    printf("Main function: Thread has terminated\n");

    return 0;
}
