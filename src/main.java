public class main {
    public static void main(String[] args)
    {
        ManageInventory Man = new ManageInventory();
        boolean tick = Man.RemoveItem(10000000);
        if(tick){
            System.out.println("TRUE");
        }else{
            System.out.println("You FAIL");
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
