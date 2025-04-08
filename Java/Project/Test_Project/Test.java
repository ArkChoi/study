package Project.Test_Project;

import java.io.IOException;

//단 하나의 목적 터미널 clear 표현 때문에 작성중임

public class Test {
    public static void main(String[] args) throws InterruptedException, IOException {
        System.out.println("Hello Java"); //처음 터미널 출력
        Thread.sleep(5000); //5초간 코드 대기
        final String os = System.getProperty("os.name"); //os정보를 받아오는 듯 하다 아직 미숙지
        if(os.contains("Windows")){ //Windows 일때 시행하는 듯 하다 아직 미숙지지
            new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor(); //여기는 완전 미숙지 부분
        }
        else{ //Linux를 상정해 둔 듯 하다 미숙지지
            Runtime.getRuntime().exec("clear"); //Linux 명령어를 시행했다.. 메소드 미숙지지
        }
        System.out.println("Hello Java 22"); //마무리 출력
    }
}
