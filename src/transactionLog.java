import java.sql.*;
import java.util.Vector;

public class transactionLog {
    private Connection connect;
    private Statement state;
    private ResultSet resSet;

    public transactionLog(){
        try{
            java.sql.Driver d=new com.mysql.jdbc.Driver();

            connect = DriverManager.getConnection("jdbc:mysql://localhost:3306/users?useSSL=false", "root", "root");
            state = connect.createStatement();
        }catch(Exception exep){
            exep.printStackTrace();
            System.out.println("Error: " + exep);
        }
    }

    public void close(){
        try{
            connect.close();
        }catch(Exception E){

        }
    }

    public boolean AddItem(String Name, int ID, int Qty, int Cost){
        boolean val = false;
        try{
            String QQ = "INSERT into log_table (Name,ID,Qty,Cost) VALUES (\"" + Name + "\"," + ID + ",\"" + Qty + "\"," + Cost + ")";
            state.execute(QQ);
            val = true;
        }catch(SQLException exep){
            exep.printStackTrace();
        }
        return val;
    }

    public Vector PullData(){
        Vector v = new Vector();
        try{
            Statement st = connect.createStatement();
            String getFrom = ("SELECT * FROM log_table ORDER BY ID;");
            ResultSet rs = st.executeQuery(getFrom);
            while(rs.next()){
                String name = rs.getString("Name");
                int ID = rs.getInt("ID");
                int Qty = rs.getInt("Qty");
                int Cost = rs.getInt("Cost");
                Vector temp = new Vector();
                temp.addElement(name);
                temp.addElement(ID);
                temp.addElement(Qty);
                temp.addElement(Cost);
                v.addElement(temp);
            }
        }catch(Exception exep){
            exep.printStackTrace();
        }
        return v;
    }
}
