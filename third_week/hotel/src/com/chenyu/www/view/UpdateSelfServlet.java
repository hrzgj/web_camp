package com.chenyu.www.view;

import com.chenyu.www.po.User;
import com.chenyu.www.service.UserService;
import com.chenyu.www.util.AppMD5Util;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "UpdateSelfServlet")
public class UpdateSelfServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        User user = (User) request.getSession().getAttribute("user");
        user.setUserName(request.getParameter("user_name"));
        user.setUserPassword(request.getParameter("user_password"));
        user.setUserPhone(request.getParameter("user_phone"));
        user.setUserIdNumber(request.getParameter("user_idNumber"));
        UserService u=new UserService();
        u.Update(user,request,response);

    }
}
