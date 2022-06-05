# 명령어 kill

**프로세스에 특정한 signal을 보내는 명령어로, 일반적으로 종료되지 않는 프로세스를 종료시킬 때 많이 사용한다.**

아래와 같이 사용할 수 있다.

` kill -[signal번호] [프로세스 PID] `

ex) kill -9 26
***

>kill 명령어에 -l 옵션을 사용하면 다음과 같이 시그널의 번호와 이름이 출력된다.

![kill -l](https://user-images.githubusercontent.com/104710548/172044510-dde23c34-cd85-42d7-b2a1-40393ce14fd9.png)

>자주 사용되어지는 시그널은 다음과 같다.

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


***
# 명령어 top
**현재 OS의 상태를 나타내며 메모리 사용량, CPU 사용량, 실행중인 프로세스 등을 나타낸다.**

>명령어 top을 사용하면 다음과 같이 시스템 상태를 나타낸다.

![top](https://user-images.githubusercontent.com/104710548/172045891-464df0c4-a865-40a5-9298-77efa8bfe9b7.png)

**첫 줄에는 시스템 시간, OS가 살아있는 시간, 유저의 세션 수를 나타낸다.**

**Load Average : CPU Load의 이동 평균을 표시하며 앞에서부터 1분, 5분, 15분에 대한 평균값을 나타낸다.**

CPU Load란 CPU가 수행하는 작업의 양이다.

---
**Task : 현재 프로세스들의 상태를 나타낸다.**

* total : 전체 프로세스

* running : 실행 중인 프로세스

* sleeping : 대기 상태인 프로세스

* zombies : 좀비상태인 프로세스

---
**CPU : CPU가 어떻게 사용되고 있는지 그 사용률을 보여주는 영역**

* us : 프로세스의 유저 영역에서의 CPU 사용률

* sy : 프로세스의 커널 영역에서의 CPU 사용률

* ni : 프로세스의 우선순위(priority) 설정에 사용하는 CPU 사용률

* id : 사용하고 있지 않는 비율

* wa : IO가 완료될때까지 기다리고 있는 CPU 비율

* hi : 하드웨어 인터럽트에 사용되는 CPU 사용률

* si : 소프트웨어 인터럽트에 사용되는 CPU 사용률

* st : CPU를 VM에서 사용하여 대기하는 CPU 비율

---
**메모리 사용량 : Mem이라 표시되어 있는 부분은 RAM의 메모리 영역이고, Swap으로 표기된 부분은 디스크를 메모리처럼 사용한다.**

**이 영역은 디스크이기 때문에 속도가 느리다.**

* total : 총 메모리 양

* free : 사용 가능한 메모리 양

* used : 사용중인 메모리 양

***
>top 명령어는 다음과 같이 각 프로세스에 대한 상세한 내용도 나타낸다.

![detail](https://user-images.githubusercontent.com/104710548/172046147-6300412f-fe0f-41ad-9e80-e1c64f836b74.png)

**top 명령어를 실행시킨 상태에서 k를 누르면 kill 명령어를 사용할 수 있다.**
***
# 명령어 ps
**터미널에서 실행한 사용자 프로세스에 대한 정보를 나타낸다.**

아래와 같이 사용할 수 있다.

```
ps
ps -[옵션]
```

![ps](https://user-images.githubusercontent.com/104710548/172046337-d60fc99e-815a-474e-870c-dfd600d2cb28.png)

* PID : 프로세스 번호

* TTY : 터미널 번호

* TIME : 해당 프로세스가 사용한 CPU 시간의 양

* CMD : 프로세스가 실행중인 명령

***
**명령어 PS 옵션**

* e : 실행중인 모든 프로세스의 정보를 출력한다.

* f : 프로세스에 대한 자세한 정보를 출력한다. (PPID 확인 가능)

* u : 프로세스 소유자의 이름, CPU 용량, 메모리 샤용량 등 상세 정보를 출력한다.

* a : 터미널에서 실행한 프로세스의 정보를 출력한다.

* x : 실행 중인 모든 프로세스의 정보를 출력한다.

* p pid : pid로 지정한 프로세스의 정보를 출력한다.
***
# 명령어 jobs
**작업이 중지된 상태, 백그라운드로 진행 중인 작업 상태, 변경되었지만 보고되지 않은 상태 등을 나타낸다.**

아래와 같이 사용할 수 있다.

`jobs -[옵션]`

![jobs](https://user-images.githubusercontent.com/104710548/172049085-17677f13-9927-449e-8bd8-14d072e109a4.png)

***
**명령어 jobs 옵션**

* l : 프로세스 그룹 ID를 state 필드 앞에 출력

* n : 프로세스 그룹 중에 대표 프로세스 ID를 출력

* p : 각 프로세스 ID에 대해 한 행씩 출력

* command : 지정한 명령어를 실행

***

**명령어 jobs로 알 수 있는 세션의 상태 값**

Running : 작업이 일시 중단되지 않았고 종료하지 않고 계속 진행 중임

* Done : 작업이 완료되어 0을 반환하고 종료 했음을 의미

* Done(code) : 작업이 정삭적으로 완료되었으며, 0이 아닌 코드를 반환했음을 의미

* Stopped : 작업이 일시 중단

* Stopped(SIGTSTP) : SIGTSTP 신호가 작업을 일시 중단

* Stopped(SIGSTOP) : SIGSTOP 신호가 작업을 일시 중단

* Stopped(SIGTTIN) : SIGTTIN 신호가 작업을 일시 중단

* Stopped(SIGTTOU) : SIGTTOU 신호가 작업을 일시 중단
