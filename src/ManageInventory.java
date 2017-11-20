import java.sql.*;

public class ProductTransactionData{
    private connection connect;
    private Statement state;
    private ResultSet resSet;

    private Vector vec = new Vector();

    public ProductTransactionData(){
        try{
            java.sql.Driver d=new com.mysql.jdbc.Driver();

            connect = DriverManager.getConnection("jdbc:mysql://localhost:3306/users", "root", "0000");
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

    public boolean AddITEM(String Name, int ID, int Qty, int Cost){
        boolean val = false;
        try{
            String QQ = "INSERT into inv_table (Name,ID,Qty,Cost) VALUES (\"" + Name + "\"," + ID + ",\"" + Qty + "\"," + Cost + ")";
            val = state.execute(QQ);
        }catch(SQLException exep){
            exep.printStackTrace();
        }
        return val;
    }
}