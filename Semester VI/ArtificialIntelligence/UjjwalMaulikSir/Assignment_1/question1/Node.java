public class Node {
    private String value;
    public Node[] branch;

    Node(String value, int num) {
        setValue(value);
        setBranchNumber(num);
    }

    public String getValue () {
        return value;
    }

    public void setValue (String value) {
        this.value = value;
    }

    public void setBranchNumber (int num) {
        if(num != 0){
            branch = new Node[num];
        }
    }
    public int getBranchNumber () {
        return branch.length;
    }
}
