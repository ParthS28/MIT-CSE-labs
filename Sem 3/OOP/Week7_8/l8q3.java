// Write a JavaFX application program that obtains two floating point numbers in two text fields
// from the user and displays the sum, product, difference and quotient of these numbers  
// using Canvas on clicking compute button with a calculator image placed on it

import javafx.application.Application; 
import javafx.scene.Scene; 
import javafx.scene.control.*; 
import javafx.scene.layout.*; 
import javafx.event.ActionEvent; 
import javafx.event.EventHandler; 
import javafx.scene.control.Label; 
import javafx.stage.Stage; 
import javafx.scene.image.*; 
import javafx.scene.paint.Color; 
import javafx.geometry.Insets; 
import javafx.geometry.Pos; 
import javafx.scene.canvas.*; 
import javafx.scene.image.ImageView; 
import javafx.scene.image.Image;
import java.io.FileInputStream; 
import java.io.*;

public class l8q3 extends Application { 
	float num1, num2;

	public void start(Stage s) throws Exception{
		s.setTitle("Calculator");
		s.setWidth(500);
		s.setHeight(500);

		FileInputStream input=new FileInputStream("./calculator.jpeg");

		Image image = new Image(input); 
		ImageView img=new ImageView(image);

		img.setPreserveRatio(true); 
		img.setFitHeight(30);

		Label b = new Label("Welcome");
		TextField tfnum1 = new TextField("");
		Label lbnum1 = new Label("Number 1: "); 
		lbnum1.setLabelFor(tfnum1);
		TextField tfnum2 = new TextField("");
		Label lbnum2 = new Label("Number 2: "); 
		lbnum2.setLabelFor(tfnum2);
		Label sum = new Label();
		Label product = new Label();
		Label difference = new Label();
		Label quotient = new Label();
		sum.setVisible(false); 
		product.setVisible(false); 
		difference.setVisible(false); 
		quotient.setVisible(false);
		Button btn = new Button();
		btn.setGraphic(img);

		btn.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent arg0) { 
				try{
					num1 = Float.parseFloat(tfnum1.getText()); 
					num2 = Float.parseFloat(tfnum2.getText());
					sum.setText(String.format(" Sum = %f", num1+num2)); 
					product.setText(String.format(" Product = %f", num1*num2)); 
					difference.setText(String.format(" Difference = %f", num1-num2)); 
					quotient.setText(String.format(" Quotient = %f", num1/num2));

					sum.setVisible(true); 
					product.setVisible(true); 
					difference.setVisible(true);

					quotient.setVisible(true);
				}catch(java.lang.NumberFormatException ex){
					System.out.println("NumberFormatException");
				}
			}
		}
		);

		Canvas can = new Canvas(300.0f, 300.0f); 
		GraphicsContext gc = can.getGraphicsContext2D();
		gc.setFill(Color.WHITE); 
		gc.fillRect(0, 0, 300, 300);
		GridPane l = new GridPane();

		l.setPadding(new Insets(10, 10, 10, 10));
		l.setVgap(5);
		l.setHgap(5);
		l.setAlignment(Pos.BASELINE_LEFT);
		l.add(sum, 0, 0);
		l.add(product, 0, 1);
		l.add(difference, 0, 2);
		l.add(quotient, 0, 3);

		StackPane n = new StackPane(); 
		n.getChildren().addAll(can, l); 
		GridPane r = new GridPane(); 
		r.setMinSize(500, 200);

		r.setPadding(new Insets(10, 10, 10, 10));
		r.setVgap(5);
		r.setHgap(5);
		r.setAlignment(Pos.BASELINE_LEFT);
		r.add(b, 0, 0);
		r.add(lbnum1, 0, 1);
		r.add(tfnum1, 1, 1);
		r.add(lbnum2, 0, 2);
		r.add(tfnum2, 1, 2);
		r.add(btn, 2, 3);
		r.add(n, 0, 5, 2, 5);
		Scene sc = new Scene(r, 200, 200);
		s.setScene(sc);
		s.show();
	}

	public static void main(String args[]){ 
		launch(args);
	}

} 