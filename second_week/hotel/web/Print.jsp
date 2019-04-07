<%@ page import="java.util.ArrayList" %>
<%@ page import="com.chenyu.www.po.User" %>
<%@ page import="com.chenyu.www.dao.impl.UserDao" %>
<%@ page import="com.chenyu.www.dao.impl.UserDaoImpl" %><%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/7
  Time: 9:37
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<% User user = (User) session.getAttribute("user");%>
<% if (user.getIdentity().equals("普通用户"))
{ %>
<jsp:forward page="UpdateSelf.jsp"></jsp:forward>
<% }%>
 <%UserDao u=new UserDaoImpl();
ArrayList<User> list=u.getMaterialsList();
int i=1;%>
    <html>
<head>
    <title>用户信息</title>
</head>
<body style="background:url(image/timg.jpg) ;">
    <table width="800" height="200" border="1" align="center">
        <caption class = "cap1">用户信息</caption>
        <br>
        <tr>
            <th width="56" class = "th">序号</th>>
            <th width="92" class = "th">用户名</th>
            <th width="92" class = "th">用户账户</th>
            <th width="150" class = "th">用户手机</th>
            <th width="150" class = "th">身份</th>
            <th width="200" class = "th">用户身份证</th>
        </tr>

        <% for(User user1:list){  %>
        <tr>
            <td align="center" class = "td"><%=i++ %> </td>
            <td align="center" class = "td"><%=user1.getUserName() %> </td>
            <td align="center" class = "td"><%=user1.getUserAccount()%></td>
            <td align="center" class = "td"><%=user1.getUserPhone() %> </td>
            <td align="center" class = "td"><%=user1.getIdentity() %> </td>
            <td align="center" class = "td"><%=user1.getUserIdNumber() %> </td>
        </tr>
        <% }%>
        <tr><a href="Main.jsp">点击返回主菜单</a> </tr>
</table>
</body>
</html>
