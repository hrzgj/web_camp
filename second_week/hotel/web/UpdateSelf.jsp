<%@ page import="com.chenyu.www.po.User" %>
<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/7
  Time: 17:07
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<% User user = (User) session.getAttribute("user");%>
<html>
<head>
    <title>修改自己信息</title>
    <!--这个函数抄的网上代码-->
    <script type="text/javascript">
        function hideen(){
            document.all.div1.style.display="";
            document.all.ok.style.display="none";
        }
    </script>
</head>
<body style="background:url(image/timg.jpg);">
<div style="display:block;text-align:center;margin: 202px;">
    <form action="UpdateSelfServlet" method="get">
    <table align="center">
        <p></p><span style="color: green">账号：</span><%=user.getUserAccount()%>
        <p></p><span style="color: green">昵称：</span><input type="text" name="user_name" value=<%=user.getUserName()%>>
        <font color="red">${requestScope.username}</font>
        <h5 style="color: red;">昵称：32位内的字符</h5>
        <p></p><span style="color: green">手机号：</span><input type="text" name="user_phone" value=<%=user.getUserPhone()%> >
        <font color="red">${requestScope.userphone}</font>
        <h5 style="color: red;">手机号为11个数字</h5>
        <p></p><span style="color: green">身份证：</span><input type="text" name="user_idNumber" value=<%=user.getUserIdNumber()%>>
        <font color="red">${requestScope.useridNumber}</font>
        <h5 style="color: red;">身份证为18位数字</h5>
        <p></p><span style="color: green">是否修改密码：</span>
        <input type="button" name="user_password" value="OK" id="ok" onclick="hideen()" />
        <div id="div1" style="display: none">
        <input type="text" />
        </div>
        <font color="red">${requestScope.userpassword}</font>
        <p>
            <button class="button2" type="submit">点击修改</button>
            <jsp:forward page="Main.jsp"></jsp:forward>
        </p>
    </table>
    </form>
</div>
</body>
</html>
