using System;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using System.Windows.Forms;
using Windows.Devices.Bluetooth;
using Windows.Devices.Bluetooth.GenericAttributeProfile;
using Windows.Storage.Streams;

namespace BLEClient
{
    public partial class Form1 : Form
    {
        public const ulong ADRESS = 198900699824151;

        // GUID have to be lower case
        public static readonly Guid LED_SERVICE = new Guid("67555b1c-df9a-4e51-842c-b9d02692d6ca");
        public static readonly Guid FULLCOLOR_CHARACTERISTIC = new Guid("d6441569-deac-4f6b-a7b6-c95effb2cc45");
        public static readonly Guid COLORGRADIENT_CHARACTERISTIC = new Guid("55a5527c-e720-4294-a3ad-fb46dcb00aae");

        private GattDeviceService ledServive;
        private GattCharacteristic fullColorCharacteristic;
        private GattCharacteristic colorGradientCharacteristic;

        private bool suspendChanged = false;
        private System.Timers.Timer timer;
        private bool timerIsRunning = false;

        private string color = "00000000";

        public Form1()
        {
            this.InitializeComponent();

            this.timer = new System.Timers.Timer(500)
            {
                SynchronizingObject = this,
                AutoReset = false
            };

            this.timer.Elapsed += this.Timer_Elapsed;
        }

        private async void Form1_Load(object sender, EventArgs e)
        {
            var device = await BluetoothLEDevice.FromBluetoothAddressAsync(ADRESS).AsTask();
            this.ledServive = device.GetGattService(LED_SERVICE);

            // NOTE: if u want to add more Characteristic then you have to 
            // remove the device from windows10 devices and pair it again, to get the new Characteristics !!!
            this.fullColorCharacteristic = this.ledServive.GetCharacteristics(FULLCOLOR_CHARACTERISTIC).FirstOrDefault();
            this.colorGradientCharacteristic = this.ledServive.GetCharacteristics(COLORGRADIENT_CHARACTERISTIC).FirstOrDefault();

            var color = await this.ReadColor();

            this.Text = color;

            var r = color[0].ToString() + color[1].ToString();
            var g = color[2].ToString() + color[3].ToString();
            var b = color[4].ToString() + color[5].ToString();
            var w = color[6].ToString() + color[7].ToString();

            this.suspendChanged = true;
            this.trackBarR.Value = Convert.ToInt32(r, 16);
            this.trackBarG.Value = Convert.ToInt32(g, 16);
            this.trackBarB.Value = Convert.ToInt32(b, 16);
            this.trackBarW.Value = Convert.ToInt32(w, 16);
            this.suspendChanged = false;
        }

        private async void Timer_Elapsed(object sender, System.Timers.ElapsedEventArgs e)
        {

            this.Text = this.color;
            await this.WriteColor(this.color);

            this.timerIsRunning = false;
        }

        private async Task<string> ReadColor()
        {
            var result = await this.fullColorCharacteristic.ReadValueAsync().AsTask();
            var status = result.Status;
            using (var reader = DataReader.FromBuffer(result.Value))
            {
                return reader.ReadString(result.Value.Length);
            }
        }

        private async Task<bool> WriteColor(string color)
        {
            var bytes = System.Text.Encoding.ASCII.GetBytes(color);
            return await this.fullColorCharacteristic.WriteValueAsync(bytes.AsBuffer()).AsTask() == GattCommunicationStatus.Success;
        }

        private void Write()
        {
            // reset timer interval
            if (this.timerIsRunning)
            {
                this.timer.Stop();
            }

            this.timer.Start();
            this.timerIsRunning = true;
        }

        private void WriteFullColor()
        {
            var r = this.trackBarR.Value.ToString("X").PadLeft(2, '0');
            var g = this.trackBarG.Value.ToString("X").PadLeft(2, '0');
            var b = this.trackBarB.Value.ToString("X").PadLeft(2, '0');
            var w = this.trackBarW.Value.ToString("X").PadLeft(2, '0');

            this.color = r + g + b + w;
            Write();
        }

        private void WriteColorGradient()
        {
            var r1 = Convert.ToInt16(this.numericUpDownGradientR1.Value).ToString("X").PadLeft(2, '0');
            var g1 = Convert.ToInt16(this.numericUpDownGradientG1.Value).ToString("X").PadLeft(2, '0');
            var b1 = Convert.ToInt16(this.numericUpDownGradientB1.Value).ToString("X").PadLeft(2, '0');
            var w1 = Convert.ToInt16(this.numericUpDownGradientW1.Value).ToString("X").PadLeft(2, '0');
                                                       
            var r2 = Convert.ToInt16(this.numericUpDownGradientR2.Value).ToString("X").PadLeft(2, '0');
            var g2 = Convert.ToInt16(this.numericUpDownGradientG2.Value).ToString("X").PadLeft(2, '0');
            var b2 = Convert.ToInt16(this.numericUpDownGradientB2.Value).ToString("X").PadLeft(2, '0');
            var w2 = Convert.ToInt16(this.numericUpDownGradientW2.Value).ToString("X").PadLeft(2, '0');

            this.color = r1 + g1 + b1 + w1 + r2 + g2 + b2 + w2;
            Write();
        }

        private void buttonChooseColor_Click_1(object sender, EventArgs e)
        {
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                this.trackBarR.Value = this.colorDialog1.Color.R;
                this.trackBarG.Value = this.colorDialog1.Color.G;
                this.trackBarB.Value = this.colorDialog1.Color.B;
            }
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            this.WriteFullColor();
        }

        #region Form events
        private void trackBarR_ValueChanged(object sender, EventArgs e)
        {
            this.numericUpDownR.Value = this.trackBarR.Value;

            if (!this.suspendChanged)
            {
                this.WriteFullColor();
            }
        }

        private void trackBarG_ValueChanged(object sender, EventArgs e)
        {
            this.numericUpDownG.Value = this.trackBarG.Value;

            if (!this.suspendChanged)
            {
                this.WriteFullColor();
            }
        }

        private void trackBarB_ValueChanged(object sender, EventArgs e)
        {
            this.numericUpDownB.Value = this.trackBarB.Value;

            if (!this.suspendChanged)
            {
                this.WriteFullColor();
            }
        }

        private void trackBarW_ValueChanged(object sender, EventArgs e)
        {
            this.numericUpDownW.Value = this.trackBarW.Value;

            if (!this.suspendChanged)
            {
                this.WriteFullColor();
            }
        }

        private void numericUpDownR_ValueChanged(object sender, EventArgs e)
        {
            this.trackBarR.Value = (int)this.numericUpDownR.Value;
        }

        private void numericUpDownG_ValueChanged(object sender, EventArgs e)
        {
            this.trackBarG.Value = (int)this.numericUpDownG.Value;
        }

        private void numericUpDownB_ValueChanged(object sender, EventArgs e)
        {
            this.trackBarB.Value = (int)this.numericUpDownB.Value;
        }

        private void numericUpDownW_ValueChanged(object sender, EventArgs e)
        {
            this.trackBarW.Value = (int)this.numericUpDownW.Value;
        }
        #endregion

        private void buttonGradient1_Click(object sender, EventArgs e)
        {
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                this.numericUpDownGradientR1.Value = this.colorDialog1.Color.R;
                this.numericUpDownGradientG1.Value = this.colorDialog1.Color.G;
                this.numericUpDownGradientB1.Value = this.colorDialog1.Color.B;
            }
        }

        private void buttonGradient2_Click(object sender, EventArgs e)
        {
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                this.numericUpDownGradientR2.Value = this.colorDialog1.Color.R;
                this.numericUpDownGradientG2.Value = this.colorDialog1.Color.G;
                this.numericUpDownGradientB2.Value = this.colorDialog1.Color.B;
            }
        }

        private void buttonGradientUpdate_Click(object sender, EventArgs e)
        {
            WriteColorGradient();
        }

        private void numericUpDownGradientG1_ValueChanged(object sender, EventArgs e)
        {
            WriteColorGradient();
        }
    }
}
