import java.util.Random;

public class Banksies {
    int pin, PassOrFail, AuthNum;
    String CCNum, CVV;
    double total;
    Random rand = new Random();


    public Boolean BankDebit(int pin, String CCNum, String CVV, double total){
        this.pin = pin;
        this.CCNum = CCNum;
        this.CVV = CVV;
        this.total = total;

        PassOrFail = rand.nextInt(100000)+1;

        if(PassOrFail < 50000)
            return Boolean.FALSE;
        else{
            AuthNum = PassOrFail * (rand.nextInt(10)+1);
            return Boolean.TRUE;
        }
    }

    public Boolean BankCredit(String CCNum, String CVV, double total){
        this.CCNum = CCNum;
        this.CVV = CVV;
        this.total = total;

        PassOrFail = rand.nextInt(100000)+1;

        if(PassOrFail < 50000)
            return Boolean.FALSE;
        else{
            AuthNum = PassOrFail * (rand.nextInt(11)+1);
            return Boolean.TRUE;
        }
    }
}
