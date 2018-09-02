namespace BLEClient
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.trackBarR = new System.Windows.Forms.TrackBar();
            this.numericUpDownR = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownG = new System.Windows.Forms.NumericUpDown();
            this.trackBarG = new System.Windows.Forms.TrackBar();
            this.numericUpDownB = new System.Windows.Forms.NumericUpDown();
            this.trackBarB = new System.Windows.Forms.TrackBar();
            this.numericUpDownW = new System.Windows.Forms.NumericUpDown();
            this.trackBarW = new System.Windows.Forms.TrackBar();
            this.button3 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarR)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownR)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownG)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarG)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownW)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarW)).BeginInit();
            this.SuspendLayout();
            // 
            // trackBarR
            // 
            this.trackBarR.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.trackBarR.Location = new System.Drawing.Point(12, 111);
            this.trackBarR.Maximum = 255;
            this.trackBarR.Name = "trackBarR";
            this.trackBarR.Size = new System.Drawing.Size(776, 45);
            this.trackBarR.TabIndex = 2;
            this.trackBarR.ValueChanged += new System.EventHandler(this.trackBarR_ValueChanged);
            // 
            // numericUpDownR
            // 
            this.numericUpDownR.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.numericUpDownR.Location = new System.Drawing.Point(794, 111);
            this.numericUpDownR.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDownR.Name = "numericUpDownR";
            this.numericUpDownR.Size = new System.Drawing.Size(95, 20);
            this.numericUpDownR.TabIndex = 7;
            this.numericUpDownR.ValueChanged += new System.EventHandler(this.numericUpDownR_ValueChanged);
            // 
            // numericUpDownG
            // 
            this.numericUpDownG.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.numericUpDownG.Location = new System.Drawing.Point(794, 162);
            this.numericUpDownG.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDownG.Name = "numericUpDownG";
            this.numericUpDownG.Size = new System.Drawing.Size(95, 20);
            this.numericUpDownG.TabIndex = 9;
            this.numericUpDownG.ValueChanged += new System.EventHandler(this.numericUpDownG_ValueChanged);
            // 
            // trackBarG
            // 
            this.trackBarG.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.trackBarG.Location = new System.Drawing.Point(12, 162);
            this.trackBarG.Maximum = 255;
            this.trackBarG.Name = "trackBarG";
            this.trackBarG.Size = new System.Drawing.Size(776, 45);
            this.trackBarG.TabIndex = 8;
            this.trackBarG.ValueChanged += new System.EventHandler(this.trackBarG_ValueChanged);
            // 
            // numericUpDownB
            // 
            this.numericUpDownB.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.numericUpDownB.Location = new System.Drawing.Point(794, 213);
            this.numericUpDownB.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDownB.Name = "numericUpDownB";
            this.numericUpDownB.Size = new System.Drawing.Size(95, 20);
            this.numericUpDownB.TabIndex = 11;
            this.numericUpDownB.ValueChanged += new System.EventHandler(this.numericUpDownB_ValueChanged);
            // 
            // trackBarB
            // 
            this.trackBarB.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.trackBarB.Location = new System.Drawing.Point(12, 213);
            this.trackBarB.Maximum = 255;
            this.trackBarB.Name = "trackBarB";
            this.trackBarB.Size = new System.Drawing.Size(776, 45);
            this.trackBarB.TabIndex = 10;
            this.trackBarB.ValueChanged += new System.EventHandler(this.trackBarB_ValueChanged);
            // 
            // numericUpDownW
            // 
            this.numericUpDownW.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.numericUpDownW.Location = new System.Drawing.Point(794, 264);
            this.numericUpDownW.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.numericUpDownW.Name = "numericUpDownW";
            this.numericUpDownW.Size = new System.Drawing.Size(95, 20);
            this.numericUpDownW.TabIndex = 13;
            this.numericUpDownW.ValueChanged += new System.EventHandler(this.numericUpDownW_ValueChanged);
            // 
            // trackBarW
            // 
            this.trackBarW.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.trackBarW.Location = new System.Drawing.Point(12, 264);
            this.trackBarW.Maximum = 255;
            this.trackBarW.Name = "trackBarW";
            this.trackBarW.Size = new System.Drawing.Size(776, 45);
            this.trackBarW.TabIndex = 12;
            this.trackBarW.ValueChanged += new System.EventHandler(this.trackBarW_ValueChanged);
            // 
            // button3
            // 
            this.button3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.button3.Location = new System.Drawing.Point(0, 310);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(895, 62);
            this.button3.TabIndex = 14;
            this.button3.Text = "update";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.buttonUpdate_Click);
            // 
            // button1
            // 
            this.button1.Dock = System.Windows.Forms.DockStyle.Top;
            this.button1.Location = new System.Drawing.Point(0, 0);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(895, 92);
            this.button1.TabIndex = 15;
            this.button1.Text = "pick color";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.buttonChooseColor_Click_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(895, 372);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.numericUpDownW);
            this.Controls.Add(this.trackBarW);
            this.Controls.Add(this.numericUpDownB);
            this.Controls.Add(this.trackBarB);
            this.Controls.Add(this.numericUpDownG);
            this.Controls.Add(this.trackBarG);
            this.Controls.Add(this.numericUpDownR);
            this.Controls.Add(this.trackBarR);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackBarR)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownR)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownG)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarG)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownW)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarW)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.TrackBar trackBarR;
        private System.Windows.Forms.NumericUpDown numericUpDownR;
        private System.Windows.Forms.NumericUpDown numericUpDownG;
        private System.Windows.Forms.TrackBar trackBarG;
        private System.Windows.Forms.NumericUpDown numericUpDownB;
        private System.Windows.Forms.TrackBar trackBarB;
        private System.Windows.Forms.NumericUpDown numericUpDownW;
        private System.Windows.Forms.TrackBar trackBarW;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button1;
    }
}

