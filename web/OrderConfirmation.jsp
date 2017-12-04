<%-- 
    Document   : OrderConfirmation
    Created on : Nov 25, 2017, 1:15:35 AM
    Author     : Scott
--%>

<%-- <%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %> --%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import = "java.util.*"%>
<%@page import = "InterfacePackages.ManageInventory"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Order Confirmation</title>
    </head>
    <body>
        <div>Order Confirmation:</div>
        <tr>Please confirm your order below.</tr>
        <form action="PayCash" method="POST">
            <table border ="1">
                <tr>
                    <td>Product ID</td>
                    <td>Product Name</td>
                    <td>Cost</td>
                    <td>Qty</td>
                </tr>
        
                <%
                    Vector v = new Vector();
                    int size = (int)pageContext.findAttribute("size");

                    //ManageInventory manInv = new ManageInventory();
                    ManageInventory manInv = (ManageInventory)session.getAttribute("manInv");
                    Vector vecInv = new Vector();
                    vecInv = manInv.PullData();
                    
                    int sub = 0, tax = 0, total = 0;
                    
//                    for(int i = 0; i < size;i++){
//                        String buy = (String)pageContext.findAttribute("v" + i);
//                        pageContext.setAttribute("buy", buy);
//                    }
                    
                    for(int i = 0; i < size; i++)
                    {
                        v.add(pageContext.findAttribute("v"+i));
                    }
                    for(int ii=0; ii<vecInv.size(); ii++){
                        session.setAttribute("v"+ii, v.get(ii));
                        
                        pageContext.setAttribute("name", null);
                        pageContext.setAttribute("ID", null);
                        pageContext.setAttribute("cost", null);
                        pageContext.setAttribute("buy", null);
                        
                        if(Integer.parseInt((String)v.get(ii)) != 0){
                            
                            Vector temp = new Vector();
                            temp = (Vector)vecInv.get(ii);
                            String name = (String)temp.get(0);
                            pageContext.setAttribute("name", name);

                            int IDi = (int)temp.get(1);
                            String ID = Integer.toString(IDi);
                            pageContext.setAttribute("ID", ID);

                            int costi = (int)temp.get(3);
                            String cost = Integer.toString(costi);
                            pageContext.setAttribute("cost", cost);

                            int buyi = Integer.parseInt((String)v.get(ii));
                            String buy = Integer.toString(buyi);
                            pageContext.setAttribute("buy", buy);
                            
                        }
                        
                %>
                <tr>
                    <td>${ID}</td>
                    <td>${name}</td>
                    <td>${cost}</td>
                    <td>${buy}</td>
                </tr>
                
            </table>
        <table>
        </form>
                <tr>
                     <% } 
                        for(int i = 0; i < size;i++)
                        {
                            Vector temp = new Vector();
                            temp = (Vector)vecInv.get(i);
                            if(Integer.parseInt((String)v.get(i)) != 0)
                            {
                                for(int j = 0; j < Integer.parseInt((String)v.get(i)); j++){
                                    sub = sub + (int)temp.get(3);
                                }
                            }
                        }
                        String subs = Integer.toString(sub);
                        pageContext.setAttribute("subs", subs);
                        session.setAttribute("subtot", subs);

                        tax = (sub / 10);
                        String taxs = Integer.toString(tax);
                        pageContext.setAttribute("taxs", taxs);
                        session.setAttribute("taxes", taxs);

                        total = sub + tax;
                        String tot = Integer.toString(total);
                        pageContext.setAttribute("tot", tot);

                        session.setAttribute("total", tot);
                       %>
                <tr><br>------------------</tr>
                <tr><br>Subtotal: ${subs} </tr>
                <tr><br>     Tax: ${taxs} </tr>
                <tr><br>   Total: ${tot}  </tr>
                <tr><br>Pay now? </tr>

        
            <tr>
                <td><form action="PayCash" method="POST">
                        <tr><input type="integer" name=cashpay value=${tot}></input></tr>
                        <input type="submit" value="Pay By Cash" name="Cash">
        </form></td>
                <td><form action="PayCredit" method="POST">
            <input type="submit" value="Pay By Credit">
        </form></td>
                <td><form action="PayDebit" method="POST">
            <input type="submit" value="Pay By Debit">
        </form></td>
                <td><form action="indexReturn" method="POST">
            <input type="submit" value="Cancel Order">
        </form></td>
            </tr>
        </table>
                       
    </body>
</html>
