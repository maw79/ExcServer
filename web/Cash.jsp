<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<%@page import = "java.util.*"%>
<%@page import = "InterfacePackages.ManageInventory"%>
<%@page import = "InterfacePackages.transactionLog"%>
<html>
    <head>
        <title>Customer Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <%--retrieve total variable--%>
        <table border ="0">
            <tr>Cash Payment System</tr>
            <tr>
                <%
                    Vector v = new Vector();
                    int size = (int)session.getAttribute("size");
                    
                    for(int i = 0; i < size;i++){
                        v.add(session.getAttribute("v"+i));
                    }

                    //ManageInventory manInv = new ManageInventory();
                    ManageInventory manInv = (ManageInventory)session.getAttribute("manInv");
                    Vector vecInv = new Vector();
                    vecInv = manInv.PullData();
                    
                    int total1 = (int)request.getAttribute("total1");
                    
                    String money = (String)session.getAttribute("total");
                    pageContext.setAttribute("money", money);
                    
                    if(total1 < Integer.parseInt(money))
                    {
                        RequestDispatcher RequetsDispatcherObj = request.getRequestDispatcher("/BSOD.jsp");
                        RequetsDispatcherObj.forward(request, response);
                    }
                    
                    transactionLog tra = (transactionLog)session.getAttribute("tra");
                    Vector Tlog = new Vector();
                    Tlog = tra.PullData();
                    for(int i = 0; i < v.size();i++){
                        int T = Integer.parseInt((String)v.get(i));
                        Vector temp = new Vector();
                        temp = (Vector)vecInv.get(i);
                        if(T != 0){
                            int ID = (int)temp.get(1);
                            Vector t2 = new Vector();
                            t2 = tra.searchData(ID);
                            for(int j = 0;j < Integer.parseInt((String)v.get(i));j++)
                            {
                                if(tra.searchData(ID) == null){
                                    tra.AddItem((String)temp.get(0), (int)temp.get(1), Integer.parseInt((String)v.get(i)) + (int)t2.get(2), (int)temp.get(3));
                                    manInv.DecQty(ID);
                                }else{
                                    tra.UpdateQty(ID, Integer.parseInt((String)v.get(i)) + (int)t2.get(2));
                                    //tra.AddItem((String)temp.get(0), (int)temp.get(1), Integer.parseInt((String)v.get(i)) + (int)t2.get(2), (int)temp.get(3));
                                    manInv.DecQty(ID);
                                }
                            }
                        }
                    }
                    
                %>
                <td>Payment Approved, Please take receipt! <br> Your change has been donated to the Wounded Warrior Project!</td>
                <%--<td>${money}</td>--%>
            </tr>
        </table>
            <td><form action="indexReturn" method="POST">
            <input type="submit" value="Start new order">
        </form></td>
    </body>
</html>
