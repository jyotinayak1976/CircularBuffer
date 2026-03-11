# Circular Buffer (Producer–Consumer) in C using pthreads

This project demonstrates a **thread-safe circular buffer (ring buffer)** implementation in **C using POSIX threads (`pthread`)**.

The program implements the classic **Producer–Consumer problem** where:

- A **producer thread** continuously inserts items into the buffer
- A **consumer thread** continuously removes items from the buffer
- Synchronization is achieved using **mutex locks and condition variables**

The circular buffer ensures efficient memory usage by **reusing a fixed-size buffer in a loop**.

---

# Why Circular Buffers Matter

Circular buffers are one of the most widely used **low-level data structures in systems programming**.

They are commonly used in:

- Operating system kernels
- Network packet processing
- Logging systems
- Streaming systems
- Real-time sensor pipelines
- High-frequency trading systems
- Message queues and event streaming platforms

Large-scale distributed systems such as **Apache Kafka** use concepts similar to circular buffers in their **append-only log structures**, which allow extremely efficient sequential writes and reads.

Understanding this primitive is an important step toward building **high-performance data systems**.

---

# Project Structure
├── circular_buffer.h
├── circular_buffer.c
├── main.c
└── README.md


### circular_buffer.h
Defines the circular buffer structure and function prototypes.

### circular_buffer.c
Contains the implementation of:

- buffer initialization
- push operation (producer)
- pop operation (consumer)

### main.c
Creates the producer and consumer threads and demonstrates the buffer in action.

---

# Circular Buffer Design

The buffer uses a fixed-size array:
BUFFER_SIZE = 8

Two pointers are used:

- **head** → position where producer inserts data
- **tail** → position where consumer removes data

The positions wrap around using modulo arithmetic:
(head + 1) % BUFFER_SIZE

This creates a **ring structure**.

---

# Synchronization Mechanism

Ensures that only one thread modifies the buffer at a time.

### Condition Variables
pthread_cond_t not_full
pthread_cond_t not_empty


They allow threads to **wait efficiently without busy looping**.

Producer waits if the buffer is full.

Consumer waits if the buffer is empty.

---

# Producer Workflow
lock mutex
while buffer is full → wait
insert item
update head
increase count
signal consumer
unlock mutex


---

# Consumer Workflow

lock mutex
while buffer is empty → wait
remove item
update tail
decrease count
signal producer
unlock mutex


---

# How to Compile

Use `gcc` with pthread support.
gcc main.c circular_buffer.c -o circular_buffer -pthread


---

# Key Systems Programming Concepts Demonstrated

This small project demonstrates several fundamental concepts:

- Thread synchronization
- Mutex locking
- Condition variables
- Producer–consumer design pattern
- Circular buffer memory management
- Avoiding busy waiting
- Concurrent data access control

These are foundational techniques used in **operating systems, networking stacks, databases, and distributed systems**.

---

# Possible Improvements

This implementation is intentionally simple for educational purposes.

Production systems may extend this with:

- **lock-free ring buffers**
- **atomic operations**
- **multiple producers and consumers**
- **batch processing**
- **cache-line alignment**
- **memory barriers**

Frameworks like the **LMAX Disruptor** and many **kernel subsystems** use highly optimized variations of this design.

---

# Future Exploration

Possible next steps include implementing:

- Lock-free circular buffers using atomic operations
- Multi-producer multi-consumer queues
- High-performance event pipelines
- Kafka-style append-only logs
- Kernel-style ring buffers

---

# License

MIT License
The implementation uses:

### Mutex
pthread_mutex_t mutex
