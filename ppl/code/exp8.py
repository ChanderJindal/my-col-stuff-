import threading
import queue
import time

# Shared queue
buffer = queue.Queue(maxsize=5)

# Producer function
def producer():
    for i in range(1, 11):
        time.sleep(1)  # Simulate production time
        item = f"Item {i}"
        buffer.put(item)
        print(f"Produced: {item}")
    buffer.put(None)  # Add a sentinel value to indicate the end of production

# Consumer function
def consumer():
    while True:
        item = buffer.get()
        if item is None:
            break  # Exit the loop if the sentinel value is encountered
        time.sleep(2)  # Simulate consumption time
        print(f"Consumed: {item}")

# Create and start the threads
producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)
producer_thread.start()
consumer_thread.start()

# Wait for the threads to finish
producer_thread.join()
consumer_thread.join()
print("\nCode by Chander Jindal\n")