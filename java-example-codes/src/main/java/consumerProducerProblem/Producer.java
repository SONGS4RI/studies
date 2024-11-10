package consumerProducerProblem;

public class Producer implements Runnable {
	private final BoundedBuffer buffer;

	public Producer(BoundedBuffer buffer) {
		this.buffer = buffer;
	}

	@Override
	public void run() {
		try {
			for (int i = 0; i < 10; i++) {
				buffer.produce(i);
				System.out.println("Produced: " + i);
				Thread.sleep(100);
			}
		} catch (InterruptedException e) {
			Thread.currentThread().interrupt();
		}
	}
}
