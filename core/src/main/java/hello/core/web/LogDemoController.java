package hello.core.web;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import hello.core.common.MyLogger;
import jakarta.servlet.http.HttpServletRequest;
import lombok.RequiredArgsConstructor;

@Controller
@RequiredArgsConstructor
public class LogDemoController {
	private final LogDemoService logDemoService;
	/* 생명주기가 리퀘스트가 들어왔을때인데
	스프링 컨테이너 오토와이어 할때 없기떄문에 오류가 난다.
	 */
	private final MyLogger myLogger;

	@RequestMapping("log-demo")
	@ResponseBody
	public String logDemo(HttpServletRequest request) {
		// 스프링 인터셉터를 통해 공통부분에 대한 처리가 가능
		String requestURL = request.getRequestURL().toString();
		myLogger.setRequestUrl(requestURL);

		myLogger.log("controller test");
		logDemoService.logic("testId");
	return "OK";
	}
}
