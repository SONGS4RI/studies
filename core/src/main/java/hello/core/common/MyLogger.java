package hello.core.common;

import java.util.UUID;

import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

import jakarta.annotation.PostConstruct;
import jakarta.annotation.PreDestroy;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Component
@Scope(value = "request")
public class MyLogger {
	private String uuid;
	private String requestUrl;

	public void log(String msg) {
		System.out.println("[" + uuid + "] " + "[" + requestUrl + "]" + msg);
	}

	@PostConstruct
	public void init() {
		String uuid = UUID.randomUUID().toString();
		System.out.println("[" + uuid + "] request scope bean created: " + this);
	}

	@PreDestroy
	public void close() {
		System.out.println("[" + uuid + "] request scope bean closed: " + this);
	}
}
