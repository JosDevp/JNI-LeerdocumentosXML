#include <stdio.h>
#include <jni.h>
#include "LeerDocumento.h"//hearder creado en C
#include <string.h>
#include <stdlib.h>

JNIEnv* create_vm(JavaVM ** jvm){// clase principal para una maquina virtual de Java
JNIEnv *env;// puntero a la interfaz del metodo nativo
JavaVMInitArgs vm_args;// argumentos de inicializacion de VM
JavaVMOption options;// cadena de opciones no estandar
options.optionString = "-Djava.class.path=/home/joseguru/Desktop/JNIC/tarjetita"; //Ruta donde se encuentran las clases
vm_args.version = JNI_VERSION_1_6; //JDK version. Indica la version del JDK
vm_args.nOptions = 1;// solamente tenemos un conjunto de opciones
vm_args.options = &options;
vm_args.ignoreUnrecognized = 0;

int ret = JNI_CreateJavaVM(jvm, (void**)&env, &vm_args);
printf("%s\n",":::::::::Retorno 0 Esta correcto...:::::::::" );
printf("%i\n",ret);
  if(ret < 0)

     printf("\nNo lanzara JVM\n");      

  return env;

}

int main(void){
JNIEnv *env;// puntero a la interfaz nativa
JavaVM *jvm;// denota una maquina virtual
jmethodID mainMethod = NULL;//metodo main
jmethodID metodo_cadena = NULL;// metodo que se obtiene de la clase Java
jclass claseJava=NULL;//nombre de la clase Java
jstring StringArg=NULL;// Dato de tipo String
jint DestroyJavaVM(JavaVM *vm);
char* valores;
int valor;
env = create_vm(&jvm);// puntero a una maquina virtual en Java
if (env == NULL) // si el puntero esta vacio
{
  printf("\nNo se puede crear el ambiente");// no se realiza nada
  return 1; 
}
claseJava = (*env)->FindClass(env,"LeerDocumento");//Realizamos la busqueda de la clase  Java
//definida localmente
if (claseJava != NULL)// si es diferente o igual a null
{
   printf("\n :::::La clase si se encuentra::::::::::\n");  
}
  else

    {
      printf("\n No se pudo encontrar la clase solicitada\n");       
    }
/*Mandamos a llamar el metodo main de la clase Java*/    
mainMethod = (*env)->GetStaticMethodID(env, claseJava, "main", "([Ljava/lang/String;)V");
/* se manda a llamar el metodo procesaXML que contiene la clase Java */
  /*como observamos el metodo no contiene parametros de ningun tipo*/
metodo_cadena = (*env)->GetStaticMethodID(env, claseJava, "cadena", "(Ljava/lang/String;)V");
//llama al metodo principal
if (mainMethod != NULL)
{
printf("\n::::::.llamando al método Principal Java:::::::\n");
(*env)->CallStaticVoidMethod(env, claseJava, mainMethod, NULL);
}

/*Pedir datos con main*/
printf("\nIngresa la cantidad de memoria a reservar.\n");
scanf("%d",&valor);
if(valor <0)
{

 printf("\n Ingrese una reserva de memoria correcta.");
 return;
}
valores = (char *) malloc(valor*sizeof(char));
if(valores == NULL)
{
  printf("\n No hay memoria disponible\n");
  return;
}else{

printf("\n Ingresa la entidad(tag) a mostrar\n");
scanf("%s",valores);
StringArg = (*env)->NewStringUTF(env,valores);
free(valores);
}
/* fin de la llamada*/
if (metodo_cadena != NULL)

{

printf("\n --Llamando a la funcion--- #(-_-)#\n");
// metodo que manda  a llamar la funcion con su parametro
(*env)->CallStaticVoidMethod(env, claseJava, metodo_cadena, StringArg);
}

(*env)->DeleteLocalRef(env,claseJava);
(*jvm)->DestroyJavaVM(jvm);
return 0;


}