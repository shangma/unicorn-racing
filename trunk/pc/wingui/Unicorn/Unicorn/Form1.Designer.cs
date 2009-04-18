namespace Unicorn
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.img = new System.Windows.Forms.PictureBox();
            this.loadbtn = new System.Windows.Forms.Button();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.labelMouse = new System.Windows.Forms.ToolStripStatusLabel();
            this.labelLongLat = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.connbtn = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.speedoBox = new System.Windows.Forms.PictureBox();
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.img)).BeginInit();
            this.statusStrip.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.speedoBox)).BeginInit();
            this.SuspendLayout();
            // 
            // img
            // 
            this.img.Location = new System.Drawing.Point(-4, 0);
            this.img.Name = "img";
            this.img.Size = new System.Drawing.Size(500, 500);
            this.img.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.img.TabIndex = 0;
            this.img.TabStop = false;
            this.img.MouseMove += new System.Windows.Forms.MouseEventHandler(this.img_MouseMove);
            this.img.Paint += new System.Windows.Forms.PaintEventHandler(this.img_Paint);
            // 
            // loadbtn
            // 
            this.loadbtn.Location = new System.Drawing.Point(8, 515);
            this.loadbtn.Name = "loadbtn";
            this.loadbtn.Size = new System.Drawing.Size(75, 23);
            this.loadbtn.TabIndex = 1;
            this.loadbtn.Text = "Load Map";
            this.loadbtn.UseVisualStyleBackColor = true;
            this.loadbtn.Click += new System.EventHandler(this.loadbtn_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.labelMouse,
            this.labelLongLat,
            this.toolStripStatusLabel1});
            this.statusStrip.Location = new System.Drawing.Point(0, 749);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(978, 22);
            this.statusStrip.TabIndex = 2;
            this.statusStrip.Text = "statusStrip1";
            // 
            // labelMouse
            // 
            this.labelMouse.Name = "labelMouse";
            this.labelMouse.Size = new System.Drawing.Size(118, 17);
            this.labelMouse.Text = "toolStripStatusLabel1";
            // 
            // labelLongLat
            // 
            this.labelLongLat.Name = "labelLongLat";
            this.labelLongLat.Size = new System.Drawing.Size(118, 17);
            this.labelLongLat.Text = "toolStripStatusLabel2";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(118, 17);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // connbtn
            // 
            this.connbtn.Location = new System.Drawing.Point(89, 515);
            this.connbtn.Name = "connbtn";
            this.connbtn.Size = new System.Drawing.Size(75, 23);
            this.connbtn.TabIndex = 3;
            this.connbtn.Text = "Connect";
            this.connbtn.UseVisualStyleBackColor = true;
            this.connbtn.Click += new System.EventHandler(this.connbtn_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(978, 771);
            this.tabControl1.TabIndex = 4;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.connbtn);
            this.tabPage1.Controls.Add(this.img);
            this.tabPage1.Controls.Add(this.loadbtn);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(970, 745);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "tabPage1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.speedoBox);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(970, 745);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "tabPage2";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // speedoBox
            // 
            this.speedoBox.Location = new System.Drawing.Point(3, 0);
            this.speedoBox.Name = "speedoBox";
            this.speedoBox.Size = new System.Drawing.Size(307, 282);
            this.speedoBox.TabIndex = 0;
            this.speedoBox.TabStop = false;
            this.speedoBox.Paint += new System.Windows.Forms.PaintEventHandler(this.speedoBox_Paint);
            // 
            // timer2
            // 
            this.timer2.Enabled = true;
            this.timer2.Interval = 10;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(978, 771);
            this.Controls.Add(this.statusStrip);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.img)).EndInit();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.speedoBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox img;
        private System.Windows.Forms.Button loadbtn;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel labelMouse;
        private System.Windows.Forms.ToolStripStatusLabel labelLongLat;
        private System.Windows.Forms.Button connbtn;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.PictureBox speedoBox;
        private System.Windows.Forms.Timer timer2;
    }
}

