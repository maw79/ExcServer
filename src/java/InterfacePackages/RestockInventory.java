/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package InterfacePackages;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Vector;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Scott
 */
@WebServlet(name = "RestockInventory", urlPatterns = {"/RestockInventory"})
public class RestockInventory extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            
            ManageInventory manInv = new ManageInventory();
            Vector vecInv = new Vector();
            vecInv = manInv.PullData();
            
            Vector v = new Vector();
            for(int i = 0; i < vecInv.size();i++){
                v.add(request.getParameter("qty" + i));
                request.removeAttribute("qty" + i);
            }
            for(int i = 0; i < v.size();i++){
                request.setAttribute("v"+i, v.get(i));
            }
            for(int i = 0; i < v.size();i++)
            {
                Vector temp = new Vector();
                temp = (Vector)vecInv.get(i);
                int ID = (int)temp.get(1);
                int Qty = (int)temp.get(2);
                int add = Integer.parseInt((String)v.get(i));
                manInv.UpdateQty(ID, Qty + add);
            }
            
            RequestDispatcher RequetsDispatcherObj =request.getRequestDispatcher("/index.jsp");
            RequetsDispatcherObj.forward(request, response);
            
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet RestockInventory</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet RestockInventory at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
