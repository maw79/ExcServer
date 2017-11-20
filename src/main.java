import java.util.Vector;

public class main {
    public static void main(String[] args)
    {
        ManageInventory Man = new ManageInventory();
        Man.UpdateCost(12341234, 15000);
        Vector v = new Vector();
        v  = Man.PullData();
        for(int i = 0; i < v.size(); i++){
            Vector temp = new Vector();
            System.out.println(v.elementAt(i));
        }
        //INTERFACE: customer transaction
            //accept product ID from scanner

            //accept product quantity

            //decrement product quantity from inventory

            //repeat above to accept all products scanned

            //prompt for payment method

            //send payment verification to bank if card

            //get approval or denial from bank if card (boolean)

            //accept bills if cash, deny if wrinkly bill

            //prompt for more cash if remaining balance > 0

            //print out receipt

        //INTERFACE: manager menu

        //INTERFACE: restocker menu
    }
}
