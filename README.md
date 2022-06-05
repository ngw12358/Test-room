# 명령어 kill

프로세스에 특정한 signal을 보내는 명령어로, 일반적으로 종료되지 않는 프로세스를 종료시킬 때 많이 사용한다.

아래와 같이 사용할 수 있다.

` kill -[signal번호] [프로세스 PID] `

ex) kill -9 26

kill 명령어에 -l 옵션을 사용하면 다음과 같이 시그널의 번호와 이름이 출력된다.

![kill -l](https://user-images.githubusercontent.com/104710548/172044510-dde23c34-cd85-42d7-b2a1-40393ce14fd9.png)

자주 사용되어지는 시그널은 다음과 같다.

|시그널 번호|시그널|설명|
|:---:|:----:|:--------------------|
|1|SIGHUP(HUP)|종료(연결 끊기, 실행 종료)|
|2|SIGINT(INT)|종료(CTRL + C, 인터럽트)|
|3|SIGQUIT(QUIT)|종료 + 코어 덤프(CTRL + \)|
|9|SIGKILL(KILL)|종료(강제 종료)|
|15|SIGTERM(TERM)|종료(정상 종료)|
|18|SIGCONT(CONT)|정지된 프로세스 재실행|
|19|SIGSTOP(STOP)|정지|
|20|SIGTSTP(TSTP)|정지(CTRL + Z)|
