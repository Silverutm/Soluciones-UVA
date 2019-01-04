function ultima_caida() {
    var fecha;
    var index = 0;
    var contador = 0;
    var flag_status = status1[0];
    for (i = 0; i < status1.length; i++) {
        if (status1[i] == 0) {
            index = i;
        }
        if (status1[i] != flag_status) {
            flag_status = status1[i];
            if (flag_status == 0)
                ++contador;
        }
    }
    //escribe fecha y hora

    var s = "";
    var fecha_hora = times[index];
    var ia = 0;
    //Para sacar la fecha de la cadena
    for (i = 0; i < fecha_hora.length; i++) {
        if (fecha_hora[i] == "_") {
            ia = ++i;
            break;

        } else {
            s += fecha_hora[i];
        }
    }

    document.getElementById("fecha").innerHTML = s;
    var h = times[index].substring(ia, fecha_hora.length);
    document.getElementById("hora").innerHTML = h;

    //cuenta caídas
    document.getElementById("contCaidas").innerHTML = contador;

}

function check_estado_actual() {
    var estado = status1[status1.length - 1];
    console.log("check estado...")
    if (estado == 0) {
        document.getElementById("estadoActualBD").setAttribute("class", "list-group-item list-group-item-danger");
        document.getElementById("estadoActualBD").innerHTML = "Estado actual: Not running!!"
    } else if (estado == 1) {
        document.getElementById("estadoActualBD").setAttribute("class", "list-group-item list-group-item-success")
        document.getElementById("estadoActualBD").innerHTML = "Estado actual: Running"

    }
}