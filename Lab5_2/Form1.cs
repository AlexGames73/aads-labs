using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab5_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Draw();
        }

        private void Draw()
        {
            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics gr = Graphics.FromImage(bmp);
            Koha(gr, new Vector2(0, pictureBox1.Height / 3 * 2), new Vector2(pictureBox1.Width, pictureBox1.Height / 3 * 2));
            pictureBox1.Image = bmp;
        }

        private void Koha(Graphics g, Vector2 start, Vector2 end)
        {
            Pen blackPen = new Pen(Color.Black);
            Vector2 plosk = end - start;
            if (plosk.Length() < 2)
            {
                g.DrawLine(blackPen, start.X, start.Y, end.X, end.Y);
                return;
            }
            Vector2 firstA = start;
            Vector2 firstB = start + plosk / 3;
            Vector2 secondA = start + plosk / 3 * 2;
            Vector2 secondB = start + plosk;
            Vector2 plosk90 = new Vector2(-plosk.Y, plosk.X);
            plosk90 = new Vector2(plosk90.X / plosk90.Length() * ((plosk / 3).Length() * (float)Math.Sqrt(3) / -2), plosk90.Y / plosk90.Length() * ((plosk / 3).Length() * (float)Math.Sqrt(3) / -2));
            Koha(g, firstA, firstB);
            Koha(g, start + plosk / 3, start + plosk / 2 + plosk90);
            Koha(g, start + plosk / 2 + plosk90, start + plosk / 3 * 2);
            Koha(g, secondA, secondB);
        }
    }
}
