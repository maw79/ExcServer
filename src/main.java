import java.util.*;

public class main {
    public static void main(String[] args)
    {
        //int choice = 0;
        Scanner input = new Scanner(System.in);

        //creating new inventory
        ManageInventory storeInv = new ManageInventory();

        System.out.println("MAIN MENU");
        System.out.println("1: Customer Interface");
        System.out.println("2: Manager Interface");
        System.out.println("3: Restocker Interface");
        System.out.println();
        System.out.print("Enter a menu choice: ");
        try {
            int choice = input.nextInt();


            switch (choice) {
                case 1:

                    //INTERFACE: customer transaction
                    Vector transaction;
                    int productID = 1;

                    while(productID!=0) {
                        System.out.print("Enter or Scan in a Product ID (0 to finish): ");
                        //accept product ID from scanner
                        productID = input.nextInt();


                        transaction = storeInv.searchData(productID);
                        int ID = (int) transaction.get(1);
                        //System.out.println(ID);
                        if (ID == productID) {
                            //System.out.println("item found!");
                            System.out.println(transaction.get(0) + " added to cart");
                            System.out.println();

                        } else {
                            System.out.println("item not found!");
                        }
                    }

                    //accept product quantity

                    //decrement product quantity from inventory

                    //repeat above to accept all products scanned

                    //prompt for payment method

                    //send payment verification to bank if card

                    //get approval or denial from bank if card (boolean)

                    //accept bills if cash, deny if wrinkly bill

                    //prompt for more cash if remaining balance > 0

                    //print out receipt

                    //System.out.println("customer transaction interface");
                    break;

                case 2:

                    //INTERFACE: manager menu
                    //adding items to inventory database

                    //Large Items (ID 0-9)
                    storeInv.AddItem("M1 Abrams Tank", 0001, 5, 20000000);
                    //storeInv.RemoveItem(0001);

                    //Assault Rifles (ID 10-19)
                    storeInv.AddItem("Bushmaster ACR", 0011, 10, 2000);
                    storeInv.AddItem("Tavor AR", 0012, 10, 1800);

                    //Hand Guns (ID 20-29)
                    storeInv.AddItem("USP 45", 0020, 5, 750);
                    storeInv.AddItem("Glock 40", 0021, 5, 500);
                    storeInv.AddItem("M1911", 0022, 5, 600);

                    //Rocket Launchers (ID 30-39)
                    storeInv.AddItem("FGM-148 Javelin", 0030, 5, 246000);

                    //Explosives and Thrown (ID 40-49)
                    storeInv.AddItem("Hand Grenade", 0040, 50, 150);
                    storeInv.AddItem("C4 (1 lb)", 0041, 20, 20);
                    storeInv.AddItem("Flash Grenade", 0042, 50, 100);
                    storeInv.AddItem("Stun Grenade", 0043, 50, 100);

                    Vector v = new Vector();
                    v = storeInv.PullData();
                    for (int i = 0; i < v.size(); i++) {
                        Vector temp = new Vector();
                        System.out.println(v.elementAt(i));
                    }

                    FinancialTData FinT = new FinancialTData();
                    double SubT = FinT.GetSubtotal(v);
                    double tax = FinT.GetTax(SubT);
                    System.out.println("Your Subtotal is: $" + SubT);
                    System.out.println("Tax: $" + tax);
                    System.out.println("Total: $" + FinT.GetTotal(SubT, tax));

                    storeInv.close();

                    break;

                case 3:

                    //INTERFACE: restocker menu

                    System.out.println("restocker interface");
                    break;
                default:
                    System.out.println("Invalid menu choice");
            }
        }
        catch(Exception e){
        System.out.println("Invalid input");
        }
    }
}
