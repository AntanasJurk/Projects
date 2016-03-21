import ds.Kryptys;
import ds.Labirintas;
import java.awt.Color;

import vw.LabirintoIvedimas;
import vw.NaujasTaskas;
import vw.Pvz;
import vw.SpalvuNustatymas;

public class GUI extends javax.swing.JFrame {

    Labirintas l;
    NaujasTaskas t;
    public GUI() {
        initComponents();
        p.grabFocus();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        p = new vw.Piesinys();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem4 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jCheckBoxMenuItem1 = new javax.swing.JCheckBoxMenuItem();
        jMenuItem3 = new javax.swing.JMenuItem();
        jMenuItem6 = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Labirintas");

        p.setBackground(new java.awt.Color(102, 255, 102));
        p.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                pMouseMoved(evt);
            }
        });
        p.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                pMouseClicked(evt);
            }
        });
        p.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                pKeyReleased(evt);
            }
        });

        javax.swing.GroupLayout pLayout = new javax.swing.GroupLayout(p);
        p.setLayout(pLayout);
        pLayout.setHorizontalGroup(
            pLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        pLayout.setVerticalGroup(
            pLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 279, Short.MAX_VALUE)
        );

        jMenu1.setText("Valdymas");

        jMenuItem1.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_N, java.awt.event.InputEvent.CTRL_MASK));
        jMenuItem1.setText("Kurti nauja labirinta");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem1);

        jMenuItem4.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_T, java.awt.event.InputEvent.CTRL_MASK));
        jMenuItem4.setText("Nurodyti tasko padeti");
        jMenuItem4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem4ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem4);

        jMenuItem2.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_X, java.awt.event.InputEvent.CTRL_MASK));
        jMenuItem2.setText("Baigti darba");
        jMenu1.add(jMenuItem2);

        jMenuBar1.add(jMenu1);

        jMenu2.setText("Redaguoti");

        jCheckBoxMenuItem1.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_E, java.awt.event.InputEvent.CTRL_MASK));
        jCheckBoxMenuItem1.setSelected(true);
        jCheckBoxMenuItem1.setText("Redaguoti");
        jMenu2.add(jCheckBoxMenuItem1);

        jMenuItem3.setAccelerator(javax.swing.KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_C, java.awt.event.InputEvent.CTRL_MASK));
        jMenuItem3.setText("Keisti spalva");
        jMenuItem3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem3ActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItem3);

        jMenuItem6.setText("Fono spalva");
        jMenuItem6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem6ActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItem6);

        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(p, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(p, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        //JDialog tipo lango kvietimas
        LabirintoIvedimas iv = new LabirintoIvedimas(this, true);
        iv.setVisible(true);
        int la = iv.auks;
        int lp = iv.plot;
        //Kada zinomi matmenys - kuriamas labirintas
        l = new Labirintas(la, lp);
        p.setL(l);
        //labirinte sukuriame nauja taska
        l.pridetiTaska("A", 0, 0);
        //butu galima sukurti ir daugiau tasku
        this.repaint();
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void jMenuItem4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem4ActionPerformed
         
            NaujasTaskas task = new NaujasTaskas(this, true);
            task.Parametrai(l.getAukstis(), l.getPlotis());
            task.setVisible(true);
            l.Pozicija(0, task.e1, task.s1);
         this.repaint();
    }//GEN-LAST:event_jMenuItem4ActionPerformed

    private void pMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_pMouseClicked
        //tikrina ar checkbox meniu yra ijungtas ar ne
        if (jCheckBoxMenuItem1.isSelected()) {
            int x = evt.getX();
            int y = evt.getY();
            int mastelis = p.m;
            int j = x / mastelis;
            int i = y / mastelis;
                //Langelis dabartinis = (l.getLangeliai())[i][j];
                Kryptys kr;
            //cia pasiziuri kiek nutolusi pele nuo langeliu sienu
            int ats_iki_vet_sien = x % mastelis;
            int ats_iki_hor_sien = y % mastelis;
            //atimama puse langeliu ir imamas moduli tam, kad butu aisku kiek nuo vidurio nutole, 
            //taip aiskiau atrinti ar arciau kaires ar desines ir pan
            if (Math.abs(ats_iki_vet_sien - mastelis / 2)
                    > Math.abs(ats_iki_hor_sien - mastelis / 2)) {
                //vertikali siena
                    if (ats_iki_vet_sien < mastelis / 2) {
                        kr = Kryptys.KAIRE;
                    } else {
                        kr = Kryptys.DESINE;
                    }
            } else {
                //horizontali siena
                    if (ats_iki_hor_sien < mastelis / 2) {
                        kr = Kryptys.VIRSUS;
                    } else {
                        kr = Kryptys.APACIA;
                    }
            }
            l.keistiSiena(i, j, kr);
            this.repaint();
        }
    }//GEN-LAST:event_pMouseClicked

    private void pMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_pMouseMoved
        if (l != null && jCheckBoxMenuItem1.isSelected()) {
            int x=evt.getX();
            int y=evt.getY();
            int mastelis=p.m;
            int j=x/mastelis;
            //vedziojant su pele jau butu galima nustatineti ties kuria siena yra ir kuriuo langeliu
            //tada ta langeli ir krypti butu galima paduoti piesimui ir jis atvaizduotu kuria siena jus ruosiates salinti/prideti
        }
    }//GEN-LAST:event_pMouseMoved

    private void jMenuItem3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem3ActionPerformed
        SpalvuNustatymas sn = new SpalvuNustatymas(this, true);
        sn.dabartine(p.s1, p.s2, p.s3);
        sn.setVisible(true);
      Color s1 = sn.sp1;
        Color s2 = sn.sp2;
        Color s3 = sn.sp3;
        p.s1 = s1;
        p.s2 = s2;
        p.s3 = s3;
       // this.repaint();
    }//GEN-LAST:event_jMenuItem3ActionPerformed

    private void jMenuItem6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem6ActionPerformed
        //pavyzdys kaip galima sukurtoje formoje is karto nuskaityti spalvas ir jas paduoti i nurodyta piesini
        Pvz asd = new Pvz();
        asd.rodyti(p);
    }//GEN-LAST:event_jMenuItem6ActionPerformed

    private void pKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_pKeyReleased
        //su rodykliu klavisais valdomas taskas, butu gerai, 
        //jei pridetumete ir antro tasko valdyma kitas klavisais, kad matyciau, jog suprantat
        switch (evt.getKeyCode()) {
          case 38:
                l.getTaskai().get(0).eik(Kryptys.VIRSUS);
                break;
            case 39:
                l.getTaskai().get(0).eik(Kryptys.DESINE);
                break;
            case 40:
                l.getTaskai().get(0).eik(Kryptys.APACIA);
                break;
            case 37:
                l.getTaskai().get(0).eik(Kryptys.KAIRE);
                break;
        }
        this.repaint();
    }//GEN-LAST:event_pKeyReleased


    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new GUI().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItem1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;
    private javax.swing.JMenuItem jMenuItem4;
    private javax.swing.JMenuItem jMenuItem6;
    private vw.Piesinys p;
    // End of variables declaration//GEN-END:variables
}
