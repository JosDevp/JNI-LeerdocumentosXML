import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;
import java.io.File;
import java.util.Scanner;

/**
 *
 * @author Syndein
 */
public class LeerDocumento {
   
   public static String mensaje;

    public static String getMensaje() {
        return mensaje;
    }

    public static void setMensaje(String mensaje) {
        LeerDocumento.mensaje = mensaje;
    
    }
    public static void cadena(String texto){
         try {
 
	File fXmlFile = new File("tarjeta.xml");
	DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
	DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
	Document doc = dBuilder.parse(fXmlFile);
	doc.getDocumentElement().normalize();
 
	System.out.println("Elemento Raiz :" + doc.getDocumentElement().getNodeName());
 
	NodeList nList = doc.getElementsByTagName("personal");
 
	System.out.println("----------------------------");
 
	for (int temp = 0; temp < nList.getLength(); temp++) {
 
		Node nNode = nList.item(temp);
 
		System.out.println("\nElemento Actual :" + nNode.getNodeName());
 
		if (nNode.getNodeType() == Node.ELEMENT_NODE) {
 
			Element eElement = (Element) nNode;
                            if(texto.equals("id")){

                                System.out.println(" Id_Tarjeta : " + eElement.getAttribute(texto));
                            }else if(texto.equals("entidad")){
                                
                                System.out.println("Entidad : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }else if(texto.equals("chip")){
                                System.out.println("Chip : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }else if(texto.equals("marca")){
                                System.out.println("Marca : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }
                            else if(texto.equals("fecha")){
                                System.out.println("Fecha : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }
                              else if(texto.equals("nombre")){
                                System.out.println("Nombre : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }
                              else if(texto.equals("banda")){
                                System.out.println("Banda : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }
                              else if(texto.equals("firma")){
                                System.out.println("Firma : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }
                              else if(texto.equals("cvc")){
                                System.out.println("CVC : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }
                              else if(texto.equals("emisora")){
                                System.out.println("Emisora : " + eElement.getElementsByTagName(texto).item(0).getTextContent());
                            }
                            else{
                               System.out.println("No se encuentra ese [tag] dentro del documento [XML]");
                            }
			
			
			
			
 
		}
	}
    } catch (Exception e) {
	e.printStackTrace();
    }
        
    }
  
    
     public static void main(String argv[]) {
    /*   Scanner leo=new Scanner(System.in);
         System.out.println("Ingresa una entidad");
         mensaje=leo.next();
         cadena(mensaje);*/

         System.out.println("\n:::YO Java leo xml:::::\n");
         
  
   
  }

   
    
    
    
    
}
