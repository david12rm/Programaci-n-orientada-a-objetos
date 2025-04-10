import java.io.BufferedReader;
import java.io.InputStreamReader;

class Nomina{
    public static void main(String[] args) throws Exception{
        int numeroEmpleados;
        String[] cedulas=new String[50];
        String[] apellidos=new String[50];
        String[] nombres=new String[50];
        double[] horasTrabajadas=new double[50];
        double[] sueldoXHora=new double[50];
        String cedula, apellido, nombre;
        double horas,sueldo;
        double total=0;
        BufferedReader br= new BufferedReader (new InputStreamReader(System.in));
        System.out.println("Digite numero de empleados");
        numeroEmpleados= Integer.valueOf(br.readLine()).intValue();
        for (int i =0; i<numeroEmpleados;i++){
            System.out.println("\nDigite la cedula del empleado:");
            cedula=br.readLine();
            System.out.println("\nDigite el apellido del empleado:");
            apellido=br.readLine();
            System.out.println("\nDigite el nombre  del empleado:");
            nombre=br.readLine();
            System.out.println("\nDigite el numero de horas trabajadas  del empleado:");
            horas=Double.valueOf(br.readLine()).doubleValue();
            System.out.println("\nDigite el sueldo del empleado:");
            sueldo=Double.valueOf(br.readLine()).doubleValue();
            cedulas[i]=cedula;
            apellidos[i]=apellido;
            nombres[i]=nombre;
            horasTrabajadas[i]=horas;
            sueldoXHora[i]=sueldo;
        }
        for(int i=0; i< numeroEmpleados; i++){
            total=total+ horasTrabajadas[i]*sueldoXHora[i];

        }
        System.out.println("\nLa nomina total es:"+total);



    }
}