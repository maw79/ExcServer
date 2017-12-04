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
 * @author arsga
 */
@WebServlet(name = "ManagerUpdate", urlPatterns = {"/ManagerUpdate"})
public class ManagerUpdate extends HttpServlet {

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
            
            String strID = request.getParameter("itemID");
            String strCost = request.getParameter("cost");
            String strQty = request.getParameter("qty");
            
            if(strID == null){
                RequestDispatcher RequetsDispatcherObj =request.getRequestDispatcher("/BSOD.jsp");
                RequetsDispatcherObj.forward(request, response);
            }
            
            int ID = Integer.parseInt(strID);
            ManageInventory manInv = new ManageInventory();
            
            if(strQty == null){
                int Cost = Integer.parseInt(strCost);
                manInv.UpdateCost(ID, Cost);
            }else if(strCost == null){
                int Qty = Integer.parseInt(strQty);
                manInv.UpdateQty(ID, Qty);
            }else{
                int Qty = Integer.parseInt(strQty);
                int Cost = Integer.parseInt(strCost);
                manInv.UpdateCost(ID, Cost);
                manInv.UpdateQty(ID, Qty);
            }
            
            RequestDispatcher RequetsDispatcherObj =request.getRequestDispatcher("/ManagerInt.jsp");
            RequetsDispatcherObj.forward(request, response);
            
            
            
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet ManagerUpdate</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet ManagerUpdate at " + request.getContextPath() + "</h1>");
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
