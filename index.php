  <html>
  <head>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
    <script type="text/javascript"     src="//ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
    <script type="text/javascript">window.jQuery || document.write('<script src="classes/commons/jquery/jquery-1.7.1.min.js"><\/script>')</script>
    <link href="https://gitcdn.github.io/bootstrap-toggle/2.2.2/css/bootstrap-toggle.min.css" rel="stylesheet">
    <script src="https://gitcdn.github.io/bootstrap-toggle/2.2.2/js/bootstrap-toggle.min.js"></script>
    <script src="http://malsup.github.com/jquery.form.js"></script> 


  </head>
  <body>
    <form id="myForm" name="myForm" action="onoff.php" method="post"> 
      <input type="checkbox" name="toggle" id="toggle" data-toggle="toggle" data-off="Disabled" data-on="Enabled" checked>
    </form>
    <br><br>
    <div class="panel panel-default">
    <div class="panel-heading" id="heading"></div>
    <div class="panel-body" id="body"></div>
  </div>
    <div></div>
    <script>
      $('#toggle').change(function(){
        var mode= $(this).prop('checked');
        // // submit the form 
        // $(#myForm).ajaxSubmit(); 
        // // return false to prevent normal browser submit and page navigation 
        // return false; 
        $.ajax({
          type:'POST',
          dataType:'JSON',
          url:'onoff.php',
          data:'mode='+mode,
          success:function(data)
          {
            var data=eval(data);
            message=data.message;
            success=data.success;
            $("#heading").html(success);
            $("#body").html(message);
          }
        });
      });
    </script>
  </body>
  </html>
