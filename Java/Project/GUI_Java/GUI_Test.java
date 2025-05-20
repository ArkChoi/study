package Project.GUI_Java;

import java.awt.Color; //오.. Color 클레스 쓰니깐 자동추가 됨

import javax.swing.JFrame; //저저번에 배운거, 프레임이라는 이름에 맞게 그저 설계도일 뿐 이다.
import javax.swing.JPanel; //저번에 배운운거, 판낼이란 이름에 맞게 UI환경을 구축하기 시작한다.
import javax.swing.SwingConstants;
import javax.swing.JLabel; //이번에 배울거, GUI에 글자를 남기는 용도인듯 함

public class GUI_Test{

    JFrame frame = new JFrame("Test"); // ()안은 setTitle 과 같은 작동을 함
    JPanel panel = new JPanel(); //얘는 뭐 매개변수가 없는 듯?
    JLabel label = new JLabel("Hello JGUI"); //()안에 이름은 기본적으로 지정할 텍스트를 받음

    public void JFrameSetUP(){ //전에 배운거 응용용
        frame.setSize(800, 600);
        frame.setLocation(100, 100); // (0,0) 이면 좌측 상단에 붙어버리네..
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public void JPanelSetUp(){ //이번에 배우는 것
        //오.. 프레임의 레이아웃을 지정하지 않는 메소드라고 한다다
        //이게 있어야지 프레임과 구분이 생긴다.
        frame.setLayout(null);
        //여기는 알거임
        //panel.setSize(400, 300); //이거 써도 됨
        //panel.setLocation(100, 100);
        panel.setVisible(true);

        //위에 setSize와 setLocation 을 합친 메소드임
        panel.setBounds(100, 100, 400, 300);

        //panel 색상 변경
        panel.setBackground(Color.RED); // <- 여기서 java.awt.Color 가 import 됨

        //frame 에 panel 추가하기
        frame.add(panel);
    }

    public void JLabelSetUP(){
        frame.add(label);
        //frame.pack(); //이게 뭘까요? 쓰면 창이 이상하게 나옴;;
        frame.setVisible(true);
        label.setText("Hello World!"); //label의 텍스트 정의하기
        System.out.println(label.getText()); //label의 텍스트를 String형으로 가져오기
        label.setVerticalAlignment(SwingConstants.TOP); //top 부분에 글을 정렬시킴 세로정렬용
        label.setHorizontalAlignment(SwingConstants.RIGHT); //right에 글을 정렬시킴 가로정렬용
    }

    public static void main(String[] args) {
        GUI_Test gui = new GUI_Test();
        gui.JFrameSetUP();
        //gui.JPanelSetUp(); 오 이거 어떤 관계인지 모르겠으나 panel이 있으면 밑에 label이 작동 안되네요..
        gui.JLabelSetUP();
    }
}