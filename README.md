# Prime Number Server

This project involves transforming a worker process into a server that communicates via a named pipe (FIFO). The server will listen for requests from multiple clients to compute prime numbers within a specified range.

# Functionality
Named Pipe Creation: The server creates a named pipe (/tmp/myfifo) and waits for client requests.

Request Format: Clients send requests in the format RANGE XX YY, where XX is the lower bound and YY is the upper bound.

Prime Number Calculation: Upon receiving a valid request, the server computes all prime numbers within the specified range.

Response Handling: The server sends the computed prime numbers back to the client. In case of a malformed request, it responds with a "malformed request" message.

Multiple Client Support: The server can handle requests from multiple clients, processing them one by one.

# Usage
Server: Run the server program. It will create the named pipe and wait for incoming requests.

Client: Use the client program to send requests to the server in the specified format and receive the prime number results or error messages.

# Ubuntu

To get started with the Server, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/MrThomasAnthony/OS-Lab3.git
   cd OS-Lab3

2. **Install g++ (if not already installed):**

   ```bash
   sudo apt update
   sudo apt install g++

3. **Compile the Server program:**
    ```bash
    g++ -o server prog2.c -lm

4. **Run the Craps program:**
    ```bash
    ./server
