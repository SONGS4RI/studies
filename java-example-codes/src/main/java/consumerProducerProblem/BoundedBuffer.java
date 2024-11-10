package consumerProducerProblem;

public class BoundedBuffer {
	private final int[] buffer;
	private int count, in, out;
	private final int size;

	public BoundedBuffer(int size) {
		this.buffer = new int[size];
		this.size = size;
		count = in = out = 0;
	}

	public synchronized void produce(int item) throws InterruptedException {
		while (count == size) {
			wait();
		}
		buffer[in] = item;
		in = (in + 1) % size;
		count++;
		notify();
	}

	public synchronized int consume() throws InterruptedException {
		while (count == 0) {
			System.out.println("Buffer Empty");
			wait();
		}
		int item = buffer[out];
		out = (out + 1) % size;
		count--;
		notify();
		return item;
	}
}
