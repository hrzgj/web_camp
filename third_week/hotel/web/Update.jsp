<%@ page import="com.chenyu.www.po.User" %>
<%@ page import="com.chenyu.www.dao.impl.UserDao" %>
<%@ page import="com.chenyu.www.dao.impl.UserDaoImpl" %>
<%@ page import="java.util.ArrayList" %><%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/7
  Time: 15:55
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<% User user = (User) session.getAttribute("user");%>
<% if (user.getIdentity().equals("普通用户"))
{ %>
<jsp:forward page="identityError.jsp"></jsp:forward>
<% }%>
<%
    UserDao u=new UserDaoImpl();
    ArrayList<User> list=u.getMaterialsList();
    %>
<html>
<head>
    <title>修改用户信息</title>
</head>
<body>
<h1>功能未完善</h1>
</body>
</html>
