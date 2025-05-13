//작동이 잘 되나 그저 복사 코드라 아무것도 모르는 상태다.
package Project.Keyinput;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class KeyInput2 extends JFrame{
    private JLabel keyMessage[];
	
	public KeyInput2() {
		super("keyListener 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e) {
			int keyCode = e.getKeyCode();
			char keyChar = e.getKeyChar();
			
			keyMessage[0].setText(Integer.toString(keyCode));		// 키코드
			keyMessage[1].setText(Character.toString(keyChar));		// 유니코드 문자, 대응하는 문자 없을 시 ㅁ
			keyMessage[2].setText(e.getKeyText(keyCode));			// 이름 문자열
		}});
		
		keyMessage = new JLabel[3];
		keyMessage[0] = new JLabel(" getKeyCode() ");
		keyMessage[1] = new JLabel(" getKeyChar() ");
		keyMessage[2] = new JLabel(" getKeyText() ");
		
		for(int i=0; i<keyMessage.length; i++) {
			c.add(keyMessage[i]);
			keyMessage[i].setOpaque(true);
			keyMessage[i].setBackground(Color.yellow);
		}
		
		setSize(300, 300);
		setVisible(true);
		
        // 키 입력을 받을 수 있도록 포커스를 주는 코드
		c.setFocusable(true);
		c.requestFocus();
	}
	

	public static void main(String args[]) {
		new KeyInput2();
	}
}
