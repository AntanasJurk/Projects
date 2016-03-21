package vw;

import ds.Kryptys;
import ds.Labirintas;
import ds.Langelis;
import ds.Taskas;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.ArrayList;

public class Piesinys extends javax.swing.JPanel {

    //cia mastelis, kad paskui galetumem didinti ar mazinti langelio ploti/auksti
    public int m;
    //cia labirintas ka piesim
    Labirintas l;
    NaujasTaskas l1;
    //cia spalvos, kurias reiketu tinkamai naudoti vaizduojant
    public Color s1, s2, s3;

    public void setL(Labirintas l) {
        this.l = l;
    }

    /**
     * Creates new form Piesinys
     */
    public Piesinys() {
        initComponents();
        s1 = Color.white;
        s2 = Color.red;
        s3 = Color.blue;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    @Override
    public void paintComponent(Graphics g) {
        m = 50;

        if (l != null) {
            //piesti labirinta 
            super.paintComponent(g);
            this.setBackground(s1);
            this.setOpaque(true);
            int a = l.getAukstis();
            int p = l.getPlotis();
            int m1 = this.getWidth() / p;
            int m2 = this.getHeight() / a;
            m = m1;

            Langelis[][] n = l.getLangeliai();
            g.drawLine(0, 0, m * p, 0);
            g.drawLine(0, 0, 0, m * a);
            float dash1[] = {5.0f, 1.0f};
            BasicStroke dashed = new BasicStroke(1.0f, BasicStroke.CAP_BUTT, BasicStroke.JOIN_MITER, 5.0f, dash1, 0.0f);
            BasicStroke solid = new BasicStroke(3.0f);
            for (int i = 0; i < a; i++) {

                for (int j = 0; j < p; j++) {
                    Langelis s = n[i][j];
                    if (!s.galiEiti[Kryptys.DESINE.ordinal()]) {
                        g.setColor(s2);
                        ((Graphics2D) g).setStroke(solid);
                    } else {
                        g.setColor(Color.LIGHT_GRAY);
                        ((Graphics2D) g).setStroke(dashed);
                    }

                    g.drawLine(m * (j + 1), m * (i), m * (j + 1), m * (i + 1));
                    if (!s.galiEiti[Kryptys.APACIA.ordinal()]) {
                        g.setColor(s2);
                        ((Graphics2D) g).setStroke(solid);
                    } else {
                        g.setColor(Color.LIGHT_GRAY);
                        ((Graphics2D) g).setStroke(dashed);
                    }

                    g.drawLine(m * (j), m * (i + 1), m * (j + 1), m * (i + 1));
                }
            }
            ArrayList<Taskas> taskai = l.getTaskai();
            for (Taskas t : taskai) {
                Langelis l = t.vieta;
                g.setColor(s3);
                g.fillOval(l.getSt() * m + m / 10, l.getEil() * m + m / 10, m - m / 5, m - m / 5);
            }
        } else {
            g.drawString("LABIRINTAS 2000", 150, 150);
            g.drawString("Sukurkite nauja labirinta", 150, 170);

        }

    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
