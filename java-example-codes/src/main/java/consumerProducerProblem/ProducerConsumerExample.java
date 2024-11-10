package consumerProducerProblem;

public class ProducerConsumerExample {
	public static void main(String[] args) {
		BoundedBuffer buffer = new BoundedBuffer(5);
		Thread producerThread = new Thread(new Producer(buffer));
		Thread consumerThread = new Thread(new Consumer(buffer));

		consumerThread.start();
		producerThread.start();
	}
}
