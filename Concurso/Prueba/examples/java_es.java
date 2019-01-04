import java.util.*;

class guessnum {

    // Bindings a funciones en la clase Main

    private static int adivinar(int i) {
        return Main.adivinar(i);
    }

    private static int guess(int i) {
        return Main.guess(i);
    }

    private static void responder(int i) {
        Main.responder(i);
    }

    private static void answer(int i) {
        Main.answer(i);
    }

    public static void eval(int n) { // n = 100, s = 27
        adivinar(42); // Regresa 1
        adivinar(32); // Regresa 1
        adivinar(22); // Regresa -1
        adivinar(28); // Regresa 1
        adivinar(27); // Regresa 0

        responder(27); // Envia respuesta; termina ejecucion
    }


}
