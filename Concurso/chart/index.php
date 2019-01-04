<!DOCTYPE html>
<html lang="">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Inicio</title>
    <link rel="shortcut icon" href="">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.5/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.5/css/bootstrap-theme.min.css">
    <link rel="stylesheet" href="style.css">
    <style>
        body {
            padding-top: 50px;
        }
        
        .starter-template {
            padding: 40px 15px;
            text-align: center;
        }
    </style>

    <!--[if IE]>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7.3/html5shiv.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
</head>

<body>
    <?php
    if (!$_POST)
    {
      $archivo=0;         
    }
    else
    {
        $archivo = $_POST["nombre"];
        exec('./C < Final/'.$archivo.' > datos.js');
    }
?>

    <div class="container-fluid">
       <div class="container" style="margin-top:15%;">
        <center>
            <form  method="post" action="index.php">
    
    <div class="row">

    <div class="col-md-4">
    </div>
    <div class="col-md-4">
                <select name="nombre" style = " height: 50px;" class="form-control">
                    <option value="mega.txt">mega</option>
                    <option value="mil.in">mil</option>
                    <option value="A00.in">A00</option>
                    <option value="A02.in">A02</option>
                    <option value="A03.in">A03</option>
                    <option value="A04.in">A04</option>
                    <option value="A06.in">A06</option>
                    <option value="A35.in">A35</option>
                    <option value="A36.in">A36</option>
                    <option value="A37.in">A37</option>
                </select>
                <br>
            </div>
    </div>
                       
    
            <button type="submit" name="button" class="btn btn-default btn-lg">Ejecutar</button><br><br>
            <a type="button" class="btn btn-default btn-lg" href= "vista.html">Vista</a>
            </form>
        </center>
        </div>
    </div>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.5/js/bootstrap.min.js"></script>
</body>

</html>