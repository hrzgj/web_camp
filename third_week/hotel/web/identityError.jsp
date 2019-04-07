<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/7
  Time: 16:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>身份错误</title>
</head>
<body>
<center>用户权限不足，无法查看其它用户信息,稍后返回主菜单</center>
<%
    response.setHeader("refresh","3;url=/hotel_war_exploded/Main.jsp");
%>
</body>
</html>
