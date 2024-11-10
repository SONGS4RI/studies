package consumerProducerProblem;

public class Consumer implements Runnable {
	private final BoundedBuffer buffer;

	public Consumer(BoundedBuffer buffer) {
		this.buffer = buffer;
	}

	@Override
	public void run() {
		try {
			for (int i = 0; i < 10; i++) {
				int item = buffer.consume();
				System.out.println("Consumed: " + item);
				Thread.sleep(200);
			}
		} catch (InterruptedException e) {
			Thread.currentThread().interrupt();
		}
	}
}
