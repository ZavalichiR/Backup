using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ping_pong_game
{

    public partial class Form1 : Form
    {
        PictureBox picBoxPlayer, picBoxAI, picBoxBall;
        Timer gameTime;

        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;

        Size sizePlayer = new Size(25, 100);
        Size sizeAI = new Size(25, 100);
        Size sizeBall = new Size(20, 20);

        int ballSpeedX = 3;
        int ballSpeedY = 3;
        int gameTimeInterval = 1;

        public Form1()
        {
            InitializeComponent();

            this.KeyDown += new KeyEventHandler(Form1_KeyUp);

            picBoxPlayer = new PictureBox();//
            picBoxAI = new PictureBox();//Initializes the PictureBoxes
            picBoxBall = new PictureBox();//

            gameTime = new Timer();//Initializes the Timer

            gameTime.Enabled = true;//Enables the Timer
            gameTime.Interval = gameTimeInterval;//Set the timer's interval

            gameTime.Tick += new EventHandler(gameTime_Tick);//Creates the Timer's Tick event

            this.Width = SCREEN_WIDTH;//sets the Form's Width
            this.Height = SCREEN_HEIGHT;//sets the Form's Height
            this.StartPosition = FormStartPosition.CenterScreen;//opens the form in center of the screen

            picBoxPlayer.Size = sizePlayer;//sets the size of the picturebox
            picBoxPlayer.Location = new Point(picBoxPlayer.Width / 2, ClientSize.Height / 2 - picBoxPlayer.Height / 2);//sets it's location (centered)
            picBoxPlayer.BackColor = Color.Blue;//fills the picturebox with a color
            this.Controls.Add(picBoxPlayer);//adds the picture box to the form

            picBoxAI.Size = sizeAI;
            picBoxAI.Location = new Point(ClientSize.Width - (picBoxAI.Width + picBoxAI.Width / 2), ClientSize.Height / 2 - picBoxPlayer.Height / 2);
            picBoxAI.BackColor = Color.Red;
            this.Controls.Add(picBoxAI);

            picBoxBall.Size = sizeBall;
            picBoxBall.Location = new Point(ClientSize.Width / 2 - picBoxBall.Width / 2, ClientSize.Height / 2 - picBoxBall.Height / 2);
            picBoxBall.BackColor = Color.Green;
            this.Controls.Add(picBoxBall);

            

        }

        void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            int playerX = picBoxPlayer.Location.X;//picBoxPlayer.Width / 2;
            int playerY = picBoxPlayer.Location.Y; //this.PointToClient(MousePosition).Y - picBoxPlayer.Height / 2;

            int playerX2 = picBoxAI.Location.X;
            int playerY2 = picBoxAI.Location.Y;

            switch (e.KeyCode)
            {
                case Keys.Up:
                case Keys.Left:

                    playerY -= 15;
                    picBoxPlayer.Location = new Point(playerX, playerY);
  
                    break;
                case Keys.Down:
                case Keys.Right:

                    playerY += 15;
                    picBoxPlayer.Location = new Point(playerX, playerY);

                    break;

                case Keys.A:

                    playerY2 -= 15;
                    picBoxAI.Location = new Point(playerX2, playerY2);

                    break;
                case Keys.D:

                    playerY2 += 15;
                    picBoxAI.Location = new Point(playerX2, playerY2);

                    break;
            }


            
        }




        void gameTime_Tick(object sender, EventArgs e)
        {
            picBoxBall.Location = new Point(picBoxBall.Location.X + ballSpeedX, picBoxBall.Location.Y + ballSpeedY);
            gameAreaCollisions();//Checks for collisions with the form's border
            padlleCollision();//Checks for collisions with the padlles
            playerMovement();//Updates the player's position
            aiMovement();//Updates the ai's position
        }

        private void gameAreaCollisions()
        {
            if (picBoxBall.Location.Y > ClientSize.Height - picBoxBall.Height || picBoxBall.Location.Y < 0)
            {
                ballSpeedY = -ballSpeedY;
            }
            else if (picBoxBall.Location.X > ClientSize.Width)
            {
                resetBall();
            }
            else if (picBoxBall.Location.X < 0)
            {
                resetBall();
            }
        }


        private void resetBall()
        {
            picBoxBall.Location = new Point(ClientSize.Width / 2 - picBoxBall.Width / 2, ClientSize.Height / 2 - picBoxBall.Height / 2);
        }



        private void playerMovement()
        {
            //if (this.PointToClient(MousePosition).Y >= picBoxPlayer.Height / 2 && this.PointToClient(MousePosition).Y <= ClientSize.Height - picBoxPlayer.Height / 2)
            //{
            //    int playerX = picBoxPlayer.Width / 2;
            //    int playerY = this.PointToClient(MousePosition).Y - picBoxPlayer.Height / 2;

            //    picBoxPlayer.Location = new Point(playerX, playerY);
            //}
        }

        private void aiMovement()
        {
            if (ballSpeedX > 0)
            {
                //picBoxAI.Location = new Point(ClientSize.Width - (picBoxAI.Width + picBoxAI.Width / 2), picBoxBall.Location.Y - picBoxAI.Height / 2);
            }
        }

        private void padlleCollision()
        {
            if (picBoxBall.Bounds.IntersectsWith(picBoxAI.Bounds))
            {
                ballSpeedX = -ballSpeedX;
            }

            if (picBoxBall.Bounds.IntersectsWith(picBoxPlayer.Bounds))
            {
                ballSpeedX = -ballSpeedX;
            }
        }

    }
}
