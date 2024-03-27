using System;
using Android.App;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using AndroidX.AppCompat.Widget;
using AndroidX.AppCompat.App;
using Google.Android.Material.FloatingActionButton;
using Google.Android.Material.Snackbar;
using System.Net;
using Org.Apache.Http;

namespace Casper_Quadcopter_Controller
{
    [Activity(Label = "@string/app_name", Theme = "@style/AppTheme.NoActionBar", MainLauncher = true)]
    public class MainActivity : AppCompatActivity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            Xamarin.Essentials.Platform.Init(this, savedInstanceState);
            SetContentView(Resource.Layout.activity_main);

            AndroidX.AppCompat.Widget.Toolbar toolbar = FindViewById<AndroidX.AppCompat.Widget.Toolbar>(Resource.Id.toolbar);
            SetSupportActionBar(toolbar);

            // Locate all elements of content_main.xml
            TextView textView_status = FindViewById<TextView>(Resource.Id.textView_status);
            Button button_up = FindViewById<Button>(Resource.Id.button_up);
            Button button_down = FindViewById<Button>(Resource.Id.button_down);
            Button button_yawl = FindViewById<Button>(Resource.Id.button_yawl);
            Button button_yawr = FindViewById<Button>(Resource.Id.button_yawr);
            Button button_rollf = FindViewById<Button>(Resource.Id.button_rollf);
            Button button_rollb = FindViewById<Button>(Resource.Id.button_rollb);
            Button button_pitchl = FindViewById<Button>(Resource.Id.button_pitchl);
            Button button_pitchr = FindViewById<Button>(Resource.Id.button_pitchr);
            Button button_capture = FindViewById<Button>(Resource.Id.button_capture);

            // Initialize key variables
            string my_url = "";        // Define a string that will store the url of the HTTP request to be sent
            string casper_status = ""; // Define a string that is displayed on the app interface to monitor the status of the quadcopter

            // Resting state is hover. Enforce this
            if (my_url != "http://192.168.4.1/hover")
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/hover";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            }


            // When the "Up" button is held
            button_up.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/up";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Down" button is held
            button_down.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/down";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Yaw L" button is held
            button_yawl.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/yawl";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Yaw R" button is held
            button_yawr.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/yawr";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Roll F" button is held
            button_rollf.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/rollf";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Roll B" button is held
            button_rollb.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/rollb";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Pitch L" button is held
            button_pitchl.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/pitchl";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Pitch R" button is held
            button_pitchr.Touch += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/pitchr";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

            // When the "Capture" button is pressed once
            button_capture.Click += async delegate
            {
                // Create a new HTTP request
                my_url = "http://192.168.4.1/capture";
                var http_request = WebRequest.Create(my_url) as HttpWebRequest;
                http_request.Method = "GET";
                // Display the response from the ESP32 on the app interface
                HttpWebResponse http_response = (HttpWebResponse)http_request.GetResponse();
                // Check the HTTP response for validity
                if (http_response.StatusCode == (HttpStatusCode)200)
                {
                    // All Good
                    using (var stream_reader = new System.IO.StreamReader(http_response.GetResponseStream()))
                    {
                        casper_status = stream_reader.ReadToEnd();

                    }
                    textView_status.Text = casper_status;
                }
                else if (http_response.StatusCode == (HttpStatusCode)404)
                {
                    // Error 404
                    textView_status.Text = "Error 404";
                }
                else
                {
                    // Other Error
                    textView_status.Text = "Something strange is going on...";
                }
                http_response.Close();

            };

        }

        public override bool OnCreateOptionsMenu(IMenu menu)
        {
            MenuInflater.Inflate(Resource.Menu.menu_main, menu);
            return true;
        }

        public override bool OnOptionsItemSelected(IMenuItem item)
        {
            int id = item.ItemId;
            if (id == Resource.Id.action_settings)
            {
                return true;
            }

            return base.OnOptionsItemSelected(item);
        }

        private void FabOnClick(object sender, EventArgs eventArgs)
        {
            View view = (View) sender;
            Snackbar.Make(view, "Replace with your own action", Snackbar.LengthLong)
                .SetAction("Action", (View.IOnClickListener)null).Show();
        }

        public override void OnRequestPermissionsResult(int requestCode, string[] permissions, [GeneratedEnum] Android.Content.PM.Permission[] grantResults)
        {
            Xamarin.Essentials.Platform.OnRequestPermissionsResult(requestCode, permissions, grantResults);

            base.OnRequestPermissionsResult(requestCode, permissions, grantResults);
        }
	}
}
