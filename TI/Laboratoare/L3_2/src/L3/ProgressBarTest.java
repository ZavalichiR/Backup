package L3;

/**
 * Created by cosmin on 10/12/16.
 */
import java.awt.Container;
import java.awt.Dimension;
import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JProgressBar;
public class ProgressBarTest extends JFrame {
    private static final long serialVersionUID = 1L;

    public ProgressBarTest() {
        super("ProgressBar test");
        // containerul care va conține componentele grafice
        final Container pane = this.getContentPane();
        // layout manager‐ul BoxLayout permite poziționarea componentelor grafice una sub alta (printre altele)
        pane.setLayout(new BoxLayout(pane, BoxLayout.Y_AXIS));
        // când se închide fereastra se închide și aplicația
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // dimensiunea ferestrei
        this.setPreferredSize(new Dimension(400, 500));
        // dimensionarea ferestrei
        this.pack();
        // va fi simulată copierea a 5 fișiere de nume și dimensiuni diferite
        for (int x = 0; x < 5; ++x) {
            final String fileName = "fisier" + x;
            final int fileSize = 100 + 20 * x;
            // pentru fiecare fișier copiat se creează câte un fir de execuție
            new Thread() {
                public void run() {
                    // se inițializează un progressBar
                    JProgressBar progressBar = new JProgressBar(0, fileSize);
                    // textul de pe progressBar
                    progressBar.setString(fileName);
                    progressBar.setStringPainted(true);
                    // se adaugă progressBar‐ul în interfața grafică
                    pane.add(progressBar);
                    // se simulează copierea prin actualizarea progressBar‐ului cu nr. de octeți copiați
                    for (int i = 0; i <= fileSize; i += 10) {
                        progressBar.setValue(i);
                        // se așteaptă 100ms pentru a se observa mai bine comportamentul aplicației
                        try {
                            Thread.sleep(100);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }.start();
        }
    }

    public static void main(String[] args) {
        new ProgressBarTest().setVisible(true);
    }
}