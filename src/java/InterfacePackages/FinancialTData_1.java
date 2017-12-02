import java.util.Vector;

public class FinancialTData {

    public FinancialTData(){

    }

    public int GetSubtotal(Vector v){
        int subT = 0;
        for(int i = 0; i < v.size(); i++){
            Vector temp = new Vector();
            temp = (Vector)v.elementAt(i);
            subT = subT + (int)temp.elementAt(3);
        }
        return subT;
    }

    public float GetTax(float SubT){
        float tax = (SubT / 10);
        return tax;
    }

    public double GetTotal(double SubT, double tax){
        double Fin = SubT + tax;
        return Fin;
    }
}
