package com.chenyu.www.view;

import com.chenyu.www.dao.impl.UserDao;
import com.chenyu.www.dao.impl.UserDaoImpl;
import com.chenyu.www.po.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet(name = "PrintServlet")
public class PrintServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        UserDao u = new UserDaoImpl();
        ArrayList<User> user =u.getMaterialsList();
        request.setAttribute("list",user);
        request.getRequestDispatcher("/Print.jsp").forward(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
