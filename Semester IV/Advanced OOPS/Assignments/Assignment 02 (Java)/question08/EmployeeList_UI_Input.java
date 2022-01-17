package java_assignments.question08;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Locale;

public class EmployeeList_UI_Input extends JFrame{
    private JTextField empCodeField;
    private JTextField empNameField;
    private JComboBox deptField;
    private JComboBox gradeField;
    private JButton saveButton;
    private JTextField basicPayField;
    private JPanel mainPanel;
    private JTextPane search_id_field;
    private JButton search_button;
    private JLabel show_value_searched;

    private ArrayList<Employee> employees = new ArrayList<>();
    private int count = 0;

    String empcode = "";
    String empname = "";
    String grade = "";
    String dept = "";
    double basic_pay = 0;
    String search_empcode = "";

    public EmployeeList_UI_Input() {
        this.add(mainPanel);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.pack();

        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                empname = empCodeField.getText();
                empcode = empNameField.getText();
                grade = (String) gradeField.getItemAt(gradeField.getSelectedIndex());
                dept = (String) deptField.getItemAt(deptField.getSelectedIndex());
                basic_pay = (double) Double.parseDouble(basicPayField.getText());
//                showDetailsInTerminal();
                AddNewEmployee();
//                SearchEmployee();
            }
        });
        search_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                search_empcode = search_id_field.getText();

                show_value_searched.setText(SearchEmployee(search_empcode));
            }
        });
    }


    private void createUIComponents() {
        // TODO: place custom component creation code here
    }

    public void AddNewEmployee() {
//        String code = dept.toUpperCase(Locale.ROOT) + count;
        boolean isDuplicate = false;
        for (Employee e : employees){
            if (e.MatchEmCode(empcode)){
                JOptionPane.showMessageDialog(null,"Employee code Exists");
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            Employee temp = new Employee();
            temp.SetDetails(empcode, empname, basic_pay, grade, dept);

            employees.add(temp);
        }
    }

    public String SearchEmployee(String emp_code){
        boolean isFound = false;
        int index = 0;
        for (; index < employees.size(); index++){
            if (employees.get(index).MatchEmCode(emp_code)) {
                isFound = true;
                System.out.println(employees.get(index).ShowDetails());
                break;
            }
//            index++;
        }
        if (!isFound){
            return "cannot find";
        }else {
            return employees.get(index).ShowDetails();
        }
    }
}
