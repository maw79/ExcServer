import java.sql.*;
import java.util.Vector;

/*
Class : transactionLog
purpose : to track the transactions of users
functions : transactionLog()
            close()
            AddItem()
            pullData()
 */

public class transactionLog {
    private Connection connect;
    private Statement state;
    private ResultSet resSet;

    /*
    Function : transactionLog()
    Purpose : to init the mySQL connection for the transactionLog class
    use : constructor
     */
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

    /*
    Function : close()
    Purpose : close connection to mySQL database
    use : transactionLog.close()
     */
    public void close(){
        try{
            connect.close();
        }catch(Exception E){

        }
    }

    /*
    Function : AddItem()
    Purpose : Add purchased item to the mySQL database
    use : transactionLog.AddItem(name, ID, Qty, Cost)
     */
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

    public boolean UpdateQty(int ID, int Qty){
        boolean val = false;
        try{
            String QQ = "UPDATE inv_table";
            String Q2 = "SET Qty = "+ Qty;
            String Q3 = "WHERE ID = "+ ID;
            String QF = QQ + "\n" + Q2 + "\n" + Q3;
            val = state.execute(QF);
        }catch(SQLException exep){
            exep.printStackTrace();
        }
        return val;
    }

    public boolean IncQty(int ID)
    {
        try{
            Vector v = new Vector();
            v = searchData(ID);
            int i = (int)v.get(2);
            UpdateQty(ID, i+1);
        }catch(Exception e){
            return false;
        }
        return true;
    }

    public boolean AddTransaction(Vector v)
    {
        try{
            for(int i = 0; i < v.size(); i++){
                Vector temp = new Vector();
                temp = (Vector)v.elementAt(i);
                if(searchData((int)temp.get(1)) != null){
                    IncQty((int)temp.get(1));
                }else{
                    AddItem((String)temp.get(0),(int)temp.get(1),1,(int)temp.get(3));
                }
            }
        }catch (Exception exep){
            exep.printStackTrace();
        }
        return true;
    }

    /*
    Function : PullData()
    Purpose : Return a vector of all items stored in the table for this item
    use : transactionLog.PullData()
     */
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


    public Vector searchData(int IDselect){
        Vector v = new Vector();
        try{
            Statement st = connect.createStatement();
            String getFrom = ("SELECT * FROM inv_table WHERE ID = '" + IDselect + "';");
            ResultSet rs = st.executeQuery(getFrom);
            if(rs.next() == true) {
                String name = rs.getString("Name");
                int ID = rs.getInt("ID");
                int Qty = rs.getInt("Qty");
                int Cost = rs.getInt("Cost");
                v.addElement(name);
                v.addElement(ID);
                v.addElement(Qty);
                v.addElement(Cost);
            }else{
                return null;
            }
        }catch (Exception exep){
            return null;
        }
        return v;
    }
}
