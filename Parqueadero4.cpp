// NOTA IMPORTNTE: leer los comentarios antes de ejecutar o modificar el codigo

// Código base hecho por el Lic. Ampudia

// Notas adicionales para el Ing. perez:
// el codigo solo funcionar para estacionar autos (se necesita de su aprobacion para prosegiur y añadir la opcion de estacionar motos)
// la variable PLACA solo acepta valores de tipo numerico. NO INGRESAR VALORES DE TIPO CARACTER
// todavia falta calcular el valor que tiene que hacer el usuario a la hora de hacer los movimientosnesesarios para eliminar un auto del estacionamiento

// Antes de empezar con las notas... Acaso invertimos roles entre Ing. y Lic.?
// Pero bueno...
// Notas del Lic. Perez al Ing. Ampudia
// Primeramente, quiero comenzar con que el codigo ha sido mejorado visual y esteticamente, para ser mas facil de leer y entender.
// Voy a buen ritmo, realizando la edicion de la funcion parquearAuto(), y empezar primeramente por renombrarlo a parquearVehiculo(). Con estos cambios, le permitiria al usuario
// Escoger si desea ingresar carro o moto, lo cual se le avisará primeramente por pantalla, pero no lo he terminado, así que no sería correcto implementarlo aún
// Por otra parte, mejore el orden en el eliminarAuto() añadiendo variables que tomaran la misma funcion que top y NULL para mantener el orden
// Si consideras que el anterior estaba mejor, por mi no habra problema, por eso subire este archivo con otro nombre para mantener vivo el archivo original
// Agregue el case 5, para que calcule el total de los carros ingresados mas el costo extra que se da por cada vehiculo que se mueva para despachar el auto deseado.
// Por alguna razon, solo toma lo de los autos ingresados, pero no toma lo de los movimientos hechos.
// Eso sería todo por mi parte por ahora, luego lo volveré a revisar porque ya esta tardecito, de todas maneras, estaré pendiente a cualquier novedad.

// Notas adicionales del Ing. Ampudia para el Lic. Perez (perdon por el cambio de roles en la nota pasada)

// Se hicieron modificaciones en el codigo, pero no se avanzo en lo absuluto.
// Sin embargo, tengo una hipotesis para slucionar el problema del aumento del dinero recogido al parquear un nuevo auto, habiendo ya existentes:
// El codigo si funciona en esta parte, pero para qeu aumente el dinero recogido (1000) por cada auto nuevo) se tienen que ingresar 2 autos.
// O sea, si tienes tres autos parqueados, tendrias un valor inicial de 3000. luego, un auto es despachado, pero se mantiene dicho valor inicial (3000).
// Al ingresar un nuevo auto, el valor inicial aumentaria a 4000, pero no se ve reflejado dicho aumento.
// Para que se puedas aumentar dicho valor, tienes que ingresar dos autos despues de despachar uno.
// Teniendo como resultado 5 autos en al parqueadero, pero solo con un valor de 4000.
// En pocas palabras, tienes que ingresar dos autos luego de eliminar uno para que el valor pueda aumentar.

// A la hora de subir estos avances, dicho problema no e solucionado. por favor solucionar dicho problema lo antes posible.

// Nota de actualizacion:
// El problema dicho anteriormente ES PROBLABLE QUE SE HAYA SOLUCINADO.
// El aumento del valor inicial se ve reflejado sin la nesecidad de añadir mas de un auto.
// Se le pide al Lic. Perez verificar el codigo lo antes posible.

// Notas adicionales del Ing. Ampudia para el Lic. Perez

// Ya se soluciono el problema del aumento desproporcional al parquear un auto.
// La solucion fue crear un contador en el metodo parquear, y otro en el metodo eliminar
// En el primer, contaria la cantidad de autos parqueado, mientras que en el segundo, tambien contara los autos, pero luego de que uno haya sido despachado
// En el metodo parquear se haria una condicion (cuentaAutos > diferencia) si se cumplia la condicion, se agregaria 1000 a la variable acumulador, permitiendo que no disminuya el dinero recogido cuando un auto esdespachado
// El dinero recogido de mostrara en la linea 108

// aun no he arreglado el inconveniente con la variable acumulador2 (aquella variable que almacena el dinero adicional resptecto al numero de movimentos por cada auto)

// Notas del Lic. Perez para el Ing. Ampudia

// Se agrego en la función parquearAuto(); la opcion para que el usuario escoja si el vehiculo que se va a ingresar es un carro o una moto.
// Esta ubicado justo despues de la sección donde se ingresa el numero de la placa.
// Esto ha traido consigo varios inconvenientes: Primeramente, se puede ingresar la cantidad de autos que deseemos de manera consecutiva, cuando ingresamos una moto, no surge problema,
// Pero cuando volvemos a ingresar un auto, el calculo se daña, a veces suma 1000, otras veces resta 1000, y en otras ocasiones suma 1500 al valor actual del acumulado
// Revise el calculo del total devengado, pero tal parece que no toma ninguno de los valores, tanto de parquear autos como de despachar auto. Al principio solo tomaba de parquearAuto(); sin embargo, ya no.
// Es necesario cambiar eso de carro/auto a vehiculo para hacerlo mas general.

// notas a dicionales del Ing. Ampudia al Lic. Perez

// Buenas noticias. se añadió la opcion de parquear motos, pero no se termina de arreglar el problema del aumento del dinero recogido al parquear un nuevo auto. (Pasdata: este comentario fue escrito por una IA)
// Comprobar el metodo toalParquear(). es probable que no tenga errores, pero no estoy seguro.
// Se le pide su colaboracion para comprobar el estado del codigo.
// También, revisar si hay alguna variable que no se esta utilizando.

// Notas adicionales del Ing. Ampudia al Lic. Prez
// buenas noticias, el codigo ya esta completado.
// la falla en el metodo total devengado() ha sido solucionada.
// Ademas, tambien se añadio la opcion de añadie el valor adicional.

// Notas adicionales del Ing. Ampudia al Lic. Prez

// Malas noticias, el codigo todavia presenta fallas.
// Si registras algun auto o moto en el parqueadero, y spawmeas la opcion (total devengado), el valor aumentará de manera epxonencial, sin que se registre otro ve¿hiculo.
// :(
// Se le pide su colaboracion para soluionar dicho inconveniente.

// Notas adicionales del Ing. Ampudia al Lic. Prez

// Los problemas dichos en las notas anteriores fueron solucionados:
// :)
// Ahora no se como explicar lo que hice; asi que le suriero que vea el metodo totalParquear().
// Ahí podras ver todos los cambios.
// De todos modos, se le pide que revise detalladamente el codigo.

#include <malloc.h>
#include <iostream>

using namespace std;
struct Parqueadero4
{
    int placa;
    Parqueadero4 *sig;
};
Parqueadero4 *topauto, *top2auto, *auxauto; // exclusivo para auto
Parqueadero4 *topmoto, *top2moto, *auxmoto; // exclusivo para moto

Parqueadero4 *actualmoto, *actualauto;
Parqueadero4 *anteriormoto, *anteriorauto;

int valorAuto = 0;
int valorMoto = 0;

int auxiliarauto = 0;
int auxiliarmoto = 0;

int parquear()
{
    int opc = 0;
    cout << "Ingrese le tipo de vehiculo que quiere parquear" << endl;
    cout << "1: Carro" << endl;
    cout << "2: Moto" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opc;

    switch (opc)
    {
    case 1: // autos
        auxauto = (Parqueadero4 *)malloc(sizeof(Parqueadero4));

        if (topauto == NULL)
        {
            topauto = auxauto;
            cout << "Ingrese la placa del auto: ";
            cin >> topauto->placa;
            topauto->sig = NULL;
            cout << "" << endl;
        }
        else
        {
            auxauto->sig = topauto;
            cout << "Ingrese la placa del siguiente auto: ";
            cin >> auxauto->placa;
            topauto = auxauto;
            cout << "" << endl;
        }
        auxiliarauto = 1000;
        valorAuto = valorAuto + auxiliarauto;
        auxiliarauto = 0;
        break;
    case 2: // motos
        auxmoto = (Parqueadero4 *)malloc(sizeof(Parqueadero4));

        if (topmoto == NULL)
        {
            topmoto = auxmoto;
            cout << "Ingrese la placa de la moto: ";
            cin >> topmoto->placa;
            topmoto->sig = NULL;
            cout << "" << endl;
        }
        else
        {
            auxmoto->sig = topmoto;
            cout << "Ingrese la placa del siguiente moto: ";
            cin >> auxmoto->placa;
            topmoto = auxmoto;
            cout << "" << endl;
        }
        auxiliarmoto = 500;
        valorMoto = valorMoto + auxiliarmoto;
        auxiliarmoto = 0;
        break;

    default:
        cout << "Opcion invalida. Intente nuevamente." << endl;
        cout << "" << endl;
        break;
    }

    return 0;
}

int mostrar()
{
    if (topauto == NULL && topmoto == NULL)
    {
        cout << "No hay vehiculos ingresados para ser mostrados. Intente por ingresar uno." << endl;
        cout << "" << endl;
        return 0;
    }

    cout << "Autos parqueados:" << endl;
    for (auxauto = topauto; auxauto != NULL; auxauto = auxauto->sig)
    {
        cout << "===" << endl;
        cout << auxauto->placa << endl;
        cout << "";
        cout << "===" << endl;
        cout << "" << endl;
    }

    cout << "Motos parqueadas:" << endl;
    for (auxmoto = topmoto; auxmoto != NULL; auxmoto = auxmoto->sig)
    {
        cout << "===" << endl;
        cout << auxmoto->placa << endl;
        cout << "";
        cout << "===" << endl;
        cout << "" << endl;
    }
    return 0;
}
int eliminarAuto = 0;
int eliminarMoto = 0;

int auxeliminarAuto = 0;
int auxeliminarMoto = 0;

int eliminar()
{

    if (topauto == NULL && topmoto == NULL)
    {
        cout << "No hay vehiculos ingresados para ser eliminados. Intente por ingresar uno" << endl;
        cout << "" << endl;
        return 0;
    }

    int placa;
    int opc2;

    cout << "Ingrese el tipo de vehiculo que va a despachar" << endl;
    cout << "1: carro" << endl;
    cout << "2: moto" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opc2;
    switch (opc2)
    {
    case 1: // elimina auto
        cout << "Ingrese el numero de la placa: ";
        cin >> placa;

        anteriorauto = NULL;
        actualauto = topauto;

        while (actualauto != NULL && actualauto->placa != placa)
        {
            anteriorauto = actualauto;
            actualauto = actualauto->sig;

            auxeliminarAuto = 100;
            eliminarAuto = eliminarAuto + auxeliminarAuto;
        }
        auxeliminarAuto = 0;

        if (actualauto == NULL)
        {
            cout << "El vehiculo con placa " << placa << " no se encuentra registrado." << endl;
            cout << "" << endl;
            return 0;
        }
        if (anteriorauto == NULL)
        {
            topauto = topauto->sig;
        }
        else
        {
            anteriorauto->sig = actualauto->sig;
        }
        cout << "Vehiculo despachado." << endl;
        delete actualauto;
        cout << "" << endl;
        break;

    case 2: // elimina moto
        cout << "Ingrese el numero de la placa: ";
        cin >> placa;

        anteriormoto = NULL;
        actualmoto = topmoto;

        while (actualmoto != NULL && actualmoto->placa != placa)
        {
            anteriormoto = actualmoto;
            actualmoto = actualmoto->sig;

            auxeliminarMoto = 50;
            eliminarMoto = eliminarMoto + auxeliminarMoto;
        }
        auxeliminarMoto = 0;

        if (actualmoto == NULL)
        {
            cout << "El vehiculo con placa " << placa << " no se encuentra registrado." << endl;
            cout << "" << endl;
            return 0;
        }
        if (anteriormoto == NULL)
        {
            topmoto = topmoto->sig;
        }
        else
        {
            anteriormoto->sig = actualmoto->sig;
        }
        cout << "Vehiculo despachado." << endl;
        delete actualmoto;
        cout << "" << endl;
        break;
    default:
        cout << "Opcion invalida. Digite nuevamente." << endl;
        break;
    }

    return 0;
}
int totalDevengado = 0;

int devengadoAuto = 0;
int devengadoMoto = 0;

int auxDevengadoAuto = 0;
int auxDevengadoMoto = 0;

int totalParquear()
{
    devengadoAuto = valorAuto + eliminarAuto;
    devengadoMoto = valorMoto + eliminarMoto;

    // valorMoto = valorMoto + eliminarMoto; (no funcional)
    // valorAuto = valorAuto + eliminarAuto; (no funcional)

    cout << "Dinero reocogio del parqueadero de autos: $" << devengadoAuto << endl;
    cout << "Dinero recogido del parqueadero de motos: $" << devengadoMoto << endl;
    totalDevengado = devengadoAuto + devengadoMoto;

    cout << "El total devengado es: $" << totalDevengado << endl;
    return 0;
}

int main()
{
    int opcion;

    do
    {
        cout << "Bienvenido al Sistema de Manejo de Parqueadero" << endl;
        cout << "" << endl;

        cout << "Opciones de Parqueadero Disponibles:" << endl;
        cout << "1. Parquear vehiculo" << endl;
        cout << "2. Mostrar vehiculos Parqueados" << endl;
        cout << "3. Despachar vehiculo" << endl;
        cout << "4. Mostrar el total devengado" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        cout << "" << endl;

        switch (opcion)
        {
        case 1:
            parquear();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            eliminar();
            break;
        case 4:
            totalParquear();
            break;
        case 5:
            cout << "Programa Finalizado, gracias por usar nuestro Software." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
            break;
        }

    } while (opcion != 5);
}
