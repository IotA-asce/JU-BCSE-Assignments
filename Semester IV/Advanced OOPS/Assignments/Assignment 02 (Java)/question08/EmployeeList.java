package java_assignments.question08;

import java.awt.*;
import java.awt.event.*;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class EmployeeList extends JFrame{
    private JTextField empCodeField;
    private JTextField empNameField;
    private JComboBox deptField;
    private JComboBox gradeField;
    private JButton saveButton;
    private JTextField basicPayField;
    private JPanel mainPanel;

    private ArrayList<Employee> employees = new ArrayList<>();
    private Scanner scan = new Scanner(System.in);
    private boolean isClicked = false;
    private int count = 0;

    EmployeeList() {
    }

    public void AddNewEmployee() {
        this.add(mainPanel);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.pack();

        final String[] name = {""};
        final String[] grade = {""};
        final String[] dept = {""};
        final String[] empcode = {""};
        final double[] basic_salary = {0};
        Employee temp = new Employee();

        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                name[0] = empCodeField.getText();
                empcode[0] = empNameField.getText();
                grade[0] = (String) gradeField.getItemAt(gradeField.getSelectedIndex());
                dept[0] = (String) deptField.getItemAt(deptField.getSelectedIndex());
                basic_salary[0] = (double) Double.parseDouble(basicPayField.getText());
                showDetailsInTerminal(temp);
            }
        });
        //take input through frame window

        String code = dept[0].toUpperCase(Locale.ROOT) + count;
//        temp.SetDetails(code, name[0], basic_salary[0], grade[0], dept[0]);

//        EmployeeList_UI_Input eil = new EmployeeList_UI_Input(temp);
        count++;
        employees.add(temp);
    }

    public void showDetailsInTerminal(Employee temp){
//        temp.SetDetails();
    }

    public void ShowDetails(){
        for (Employee e : employees){
            e.ShowDetails();
        }
    }



    public void SearchEmployee() {
        String input_code = "";

        // input the input_code from user

        boolean found = false;
        for (Employee e : employees){
            if (e.MatchEmCode(input_code)) {
                // show match
                found = true;
            }
        }
        if (!found){
            // pop up not found in database
        }
    }
}

//        JLabel label = new JLabel();
//        label.setOpaque(true);
//        label.setBackground(new Color(50,50, 50));
//        label.setBounds(125,100,500,400);
//
//        JLabel shadow = new JLabel();
//        shadow.setOpaque(true);
//        shadow.setBackground(new Color(15,15,15));
//        shadow.setBounds(135,110,500,400);
//
//        JLayeredPane jlp = new JLayeredPane();
//        jlp.setBounds(0,0,778,600);
//        jlp.add(shadow, Integer.valueOf(1));
//        jlp.add(label,Integer.valueOf(2));
//
//        JTextField textField = new JTextField();
//        textField.setBounds(200,250,350,35);
//        textField.setBackground(new Color(240,240,240));
//
//        JButton button = new JButton("SAVE");
//        button.setBounds(325,400,100,35);
//        button.setBackground(new Color(210,210,210));
//
//        this.setTitle("Employee Management");
//        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        this.setResizable(false);
//        this.setLayout(null);
//        this.setSize(778, 600);
//        this.setVisible(true);
//        this.getContentPane().setBackground(new Color(90, 90, 90));
//        this.add(jlp);
//        this.add(textField);
//        this.add(button);

